
#include "ft_ssl.h"

void			sha_init(t_fsha *fsh, t_flg *flg)
{
    if (!ft_cmp(flg->alg, "sha256"))
    {
        fsh->h[0] = 0x6A09E667;
        fsh->h[1] = 0xBB67AE85;
        fsh->h[2] = 0x3C6EF372;
        fsh->h[3] = 0xA54FF53A;
        fsh->h[4] = 0x510E527F;
        fsh->h[5] = 0x9B05688C;
        fsh->h[6] = 0x1F83D9AB;
        fsh->h[7] = 0x5BE0CD19;
        fsh->r = 64;
    }
    else
    {
        fsh->h[0] = 0x6a09e667f3bcc908;
        fsh->h[1] = 0xbb67ae8584caa73b;
        fsh->h[2] = 0x3c6ef372fe94f82b;
        fsh->h[3] = 0xa54ff53a5f1d36f1;
        fsh->h[4] = 0x510e527fade682d1;
        fsh->h[5] = 0x9b05688c2b3e6c1f;
        fsh->h[6] = 0x1f83d9abfb41bd6b;
        fsh->h[7] = 0x5be0cd19137e2179;
        fsh->r = 80;
    }
}

void	ft_sha(t_fmd5 *fmd, t_flg *flg, char *arg)
{
    t_fsha fsh;

    sha_init(&fsh, flg);
}