
#include "ft_ssl.h"

unsigned	rotr(unsigned a, unsigned b)
{
	return ((a >> b) | (a << (32 - b)));
}

void			sha_init(t_fsha *fsh, t_flg *flg)
{
    if (!ft_strcmp(flg->alg, "sha256"))
    {
        fsh->hash[0] = 0x6A09E667;
        fsh->hash[1] = 0xBB67AE85;
        fsh->hash[2] = 0x3C6EF372;
        fsh->hash[3] = 0xA54FF53A;
        fsh->hash[4] = 0x510E527F;
        fsh->hash[5] = 0x9B05688C;
        fsh->hash[6] = 0x1F83D9AB;
        fsh->hash[7] = 0x5BE0CD19;
        fsh->r = 64;
    }
    // else //for SHA512
    // {
    //     fsh->h[0] = 0x6a09e667f3bcc908;
    //     fsh->h[1] = 0xbb67ae8584caa73b;
    //     fsh->h[2] = 0x3c6ef372fe94f82b;
    //     fsh->h[3] = 0xa54ff53a5f1d36f1;
    //     fsh->h[4] = 0x510e527fade682d1;
    //     fsh->h[5] = 0x9b05688c2b3e6c1f;
    //     fsh->h[6] = 0x1f83d9abfb41bd6b;
    //     fsh->h[7] = 0x5be0cd19137e2179;
    //     fsh->r = 80;
    // }
}

unsigned	revers_data(unsigned b)
{
	return ((b >> 24) | ((b & 0xff0000) >> 8) | ((b & 0xff00) << 8) | (b << 24));
}

unsigned	*sha_update(t_fsha *fsh, char *str)
{
    int i;
    int size;
    unsigned	*data;

    fsh->len = ft_strlen(str);
    fsh->bitlen = fsh->len * 8;
	size = 1 + ((fsh->bitlen + 16 + 64) / 512);
	data = ft_memalloc(16 * size * 4);
	ft_bzero(data, 16 * size * 4);
	ft_memcpy((char *)data, str, fsh->len);
	((char *)data)[fsh->len] = 0x80;
	i = 0;
    while (i < (size * 16) - 1)
	{
		data[i] = revers_data(data[i]);
		i++;
	}
	data[((size * 512 - 64) / 32) + 1] = fsh->bitlen;
    return (data);
}

unsigned		*sha_final(t_fsha *fsh, unsigned hash[])
{
	int			i;
	int			j;
    
	i = 0;
	j = 0;
	while (i < 8)
	{
		hash[j++] = (unsigned char) (fsh->hash[i] >> 24);
		hash[j++] = (unsigned char) (fsh->hash[i] >> 16);
		hash[j++] = (unsigned char) (fsh->hash[i] >> 8);
		hash[j++] = (unsigned char) fsh->hash[i];
		i++;
	}
	return (hash);
}

void    sha_stages(t_fsha *fsh, t_alp *al, unsigned *w)
{
	int			i;
    unsigned    k[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    i = 0;
    al->a = fsh->hash[0];
    al->b = fsh->hash[1];
    al->c = fsh->hash[2];
    al->d = fsh->hash[3];
    al->e = fsh->hash[4];
    al->f = fsh->hash[5];
    al->g = fsh->hash[6];
    al->h = fsh->hash[7];
    while (i < fsh->r)
    {
        fsh->s[1] = rotr(al->e, 6) ^ rotr(al->e, 11) ^ rotr(al->e, 25);
        fsh->ch = (al->e & al->f) ^ (~al->e & al->g);
        fsh->tmp1 = al->h + fsh->s[1] + fsh->ch + k[i] + w[i];
        fsh->s[0] = rotr(al->a, 2) ^ rotr(al->a, 13) ^ rotr(al->a, 22);
        fsh->maj = (al->a & al->b) ^ (al->a & al->c) ^ (al->b & al->c);
        fsh->tmp2 = fsh->s[0] + fsh->maj;
        al->h = al->g;
        al->g = al->f;
        al->f = al->e;
        al->e = al->d + fsh->tmp1;
        al->d = al->c;
        al->c = al->b;
        al->b = al->a;
        al->a = fsh->tmp1 + fsh->tmp2;
        i++;
    }
    fsh->hash[0] += al->a;
    fsh->hash[1] += al->b;
    fsh->hash[2] += al->c;
    fsh->hash[3] += al->d;
    fsh->hash[4] += al->e;
    fsh->hash[5] += al->f;
    fsh->hash[6] += al->g;
    fsh->hash[7] += al->h;
//     i = 0;
//     while (i < 8)
//     {
//         ft_putstr(ft_itoa_un(fsh->hash[i], 16));
//         i++;
//     }
//     printf("\n");
}

void	ft_sha(t_flg *flg, t_alp *al, char *arg)
{
    t_fsha      fsh;
    unsigned    *w;
    unsigned    *hash;
    int         i;

    sha_init(&fsh, flg);
    w = (unsigned *)ft_strnew(64);
    hash = (unsigned *)ft_strnew(32);
	w = (unsigned *)sha_update(&fsh, arg);
    i = 16;
    while (i < fsh.r)
    {
        fsh.s[0] = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
        fsh.s[1] = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + fsh.s[0] + w[i - 7] + fsh.s[1];
        i++;
    }
    sha_stages(&fsh, al, w);
    put_hash(sha_final(&fsh, hash), 32);
}