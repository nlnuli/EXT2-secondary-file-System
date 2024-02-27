#ifndef _INIT_H
#define _INIT_H
#include "main.h"

#define VOLUME_NAME	"EXT2FS"   // ����
#define BLOCK_SIZE 512	       // ���С
#define DISK_SIZE	4612	   //�����ܿ���

#define DISK_START 0	       // ���̿�ʼ��ַ
#define SB_SIZE	32	           //�������С��32B

#define	GD_SIZE	32	           // ������������С��32B
#define GDT_START	(0+512)    // ������������ʼ��ַ

#define BLOCK_BITMAP (512+512) // ��λͼ��ʼ��ַ
#define INODE_BITMAP (1024+512)// inode λͼ��ʼ��ַ

#define INODE_TABLE (1536+512) // �����ڵ����ʼ��ַ 4*512
#define INODE_SIZE 64	       // ÿ��inode�Ĵ�С��64B
#define INODE_TABLE_COUNTS	4096 // inode entry ��

#define DATA_BLOCK (263680+512)	// ���ݿ���ʼ��ַ 4*512+4096*64
#define DATA_BLOCK_COUNTS	4096	// ���ݿ���

#define BLOCKS_PER_GROUP	4612 // ÿ���еĿ���

struct super_block // 32 B
{
	char sb_volume_name[16]; //�ļ�ϵͳ��
	unsigned short sb_disk_size; //�����ܴ�С
	unsigned short sb_blocks_per_group; // ÿ���еĿ���
	unsigned short sb_size_per_block;	// ���С
	char sb_pad[10];   //���
};

struct group_desc // 32 B
{
    char bg_volume_name[16]; //�ļ�ϵͳ��
    unsigned short bg_block_bitmap; //��λͼ����ʼ���
    unsigned short bg_inode_bitmap; //�������λͼ����ʼ���
    unsigned short bg_inode_table; //�����������ʼ���
    unsigned short bg_free_blocks_count; //������п�ĸ���
    unsigned short bg_free_inodes_count; //��������������ĸ���
    unsigned short bg_used_dirs_count; //���з����Ŀ¼�Ľ����
    char bg_pad[4]; //���(0xff)
};
struct inode // 64 B
{
    unsigned short i_mode;   //�ļ����ͼ�����Ȩ��
    unsigned short i_blocks; //�ļ���ռ�����ݿ����(0~7), ���Ϊ7
    unsigned short i_uid;    //�ļ�ӵ���߱�ʶ��
    unsigned short i_gid;    //�ļ����û����ʶ��
    unsigned short i_links_count; //�ļ���Ӳ���Ӽ���
    unsigned short i_flags;  //���ļ��ķ�ʽ
    unsigned long i_size;    // �ļ���Ŀ¼��С(��λ byte)
    unsigned long i_atime;   //����ʱ��
    unsigned long i_ctime;   //����ʱ��
    unsigned long i_mtime;   //�޸�ʱ��
    unsigned long i_dtime;   //ɾ��ʱ��
    unsigned short i_block[8]; //ֱ��������ʽ ָ�����ݿ��
    char i_pad[24];           //���(0xff)
};
struct dir_entry //16B
{
    unsigned short inode; //�����ڵ��
    unsigned short rec_len; //Ŀ¼���
    unsigned short name_len; //�ļ�������
    char file_type; //�ļ�����(1 ��ͨ�ļ� 2 Ŀ¼.. )
    char name[9]; //�ļ���
};


static unsigned short last_alloc_inode; // �������Ľڵ�� */
static unsigned short last_alloc_block; // �����������ݿ�� */
static unsigned short current_dir;   // ��ǰĿ¼�Ľڵ�� */

static unsigned short current_dirlen; // ��ǰ·������ */

static short fopen_table[16]; // �ļ��򿪱� */

static struct super_block sb_block[1];	// �����黺����
static struct group_desc gdt[1];	// ��������������
static struct inode inode_area[1];  // inode������
static unsigned char bitbuf[512]={0}; // λͼ������
static unsigned char ibuf[512]={0};
static struct dir_entry dir[32];   // Ŀ¼����� 32*16=512
static char Buffer[512];  // ������ݿ�Ļ�����
static char tempbuf[4096];	// �ļ�д�뻺����
static FILE *fp;	// �������ָ��


char current_path[256];    // ��ǰ·���� */

static void update_super_block(void);   //���³���������
static void reload_super_block(void);   //���س���������
static void update_group_desc(void);    //����������������
static void reload_group_desc(void);    //����������������
static void update_inode_entry(unsigned short i); //����indoe��
static void reload_inode_entry(unsigned short i); //����inode��
static void update_block_bitmap(void);  //���¿�λͼ
static void reload_block_bitmap(void);  //���ؿ�λͼ
static void update_inode_bitmap(void);  //����inodeλͼ
static void reload_inode_bitmap(void);  //����inodeλͼ
static void update_dir(unsigned short i);//����Ŀ¼
static void reload_dir(unsigned short i);//����Ŀ¼
static void update_block(unsigned short i);//�������ݿ�
static void reload_block(unsigned short i);//�������ݿ�
static int alloc_block(void);//�������ݿ�
static int get_inode(void); //�õ�inode�ڵ�
static unsigned short reserch_file(char tmp[9],int file_type,unsigned short *inode_num,unsigned short *block_num,unsigned short *dir_num);//�����ļ�
static void dir_prepare(unsigned short tmp,unsigned short len,int type);
static void remove_block(unsigned short del_num);//ɾ�����ݿ�
static void remove_inode(unsigned short del_num);//ɾ��inode�ڵ�
static unsigned short search_file(unsigned short Ino);//�ڴ��ļ����в����Ƿ��Ѵ��ļ�
static void sleep(int k);
static void initialize_disk(void);//��ʼ������


#endif // _INIT_H
