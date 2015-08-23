#include "strings.h"

#include <stdlib.h>

int strcasecmp(const char *src, const char *dst)
{
	// �啶������������ʂ��Ȃ� strcmp
	int ret;
	int src_l = strlen(src);
	int dst_l = strlen(dst);
	char *tmp_src = malloc(src_l+1);
	char *tmp_dst = malloc(dst_l+1);

	// �啶��������O�ɕ�����R�s�[
	strncpy(tmp_src,src,src_l);
	strncpy(tmp_dst,dst,dst_l);
	tmp_src[src_l] = 0x00;
	tmp_dst[dst_l] = 0x00;

	// �啶����
	_strupr(tmp_src);
	_strupr(tmp_dst);
	
	// ���ʂ� strcmp
	ret = strncmp(tmp_src,tmp_dst,dst_l);
	free(tmp_src);
	free(tmp_dst);

	return ( ret );
}


int strncasecmp(const char *src, const char *dst, size_t siz)
{
	// �啶������������ʂ��Ȃ� strncmp
	int ret;
	int src_l = strlen(src);
	char *tmp_src = malloc(src_l+1);
	char *tmp_dst = malloc(siz+1);

	// �啶��������O�ɕ�����R�s�[
	strncpy(tmp_src,src,src_l);
	strncpy(tmp_dst,dst,siz);
	tmp_src[src_l] = 0x00;
	tmp_dst[siz] = 0x00;

	// �啶����
	_strupr(tmp_src);
	_strupr(tmp_dst);
	
	// ���ʂ� strcmp
	ret = strncmp(tmp_src,tmp_dst,siz);
	free(tmp_src);
	free(tmp_dst);

	return ( ret );

}

