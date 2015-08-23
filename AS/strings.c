#include "strings.h"

#include <stdlib.h>

int strcasecmp(const char *src, const char *dst)
{
	// 大文字小文字を区別しない strcmp
	int ret;
	int src_l = strlen(src);
	int dst_l = strlen(dst);
	char *tmp_src = malloc(src_l+1);
	char *tmp_dst = malloc(dst_l+1);

	// 大文字化する前に文字列コピー
	strncpy(tmp_src,src,src_l);
	strncpy(tmp_dst,dst,dst_l);
	tmp_src[src_l] = 0x00;
	tmp_dst[dst_l] = 0x00;

	// 大文字化
	_strupr(tmp_src);
	_strupr(tmp_dst);
	
	// 普通に strcmp
	ret = strncmp(tmp_src,tmp_dst,dst_l);
	free(tmp_src);
	free(tmp_dst);

	return ( ret );
}


int strncasecmp(const char *src, const char *dst, size_t siz)
{
	// 大文字小文字を区別しない strncmp
	int ret;
	int src_l = strlen(src);
	char *tmp_src = malloc(src_l+1);
	char *tmp_dst = malloc(siz+1);

	// 大文字化する前に文字列コピー
	strncpy(tmp_src,src,src_l);
	strncpy(tmp_dst,dst,siz);
	tmp_src[src_l] = 0x00;
	tmp_dst[siz] = 0x00;

	// 大文字化
	_strupr(tmp_src);
	_strupr(tmp_dst);
	
	// 普通に strcmp
	ret = strncmp(tmp_src,tmp_dst,siz);
	free(tmp_src);
	free(tmp_dst);

	return ( ret );

}

