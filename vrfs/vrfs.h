/*
 * vrfs.h
 *
 *  Created on: 28-Jan-2018
 *      Author: rishabh
 */

#ifndef VRFS_VRFS_H_
#define VRFS_VRFS_H_
#include "../util.h"
#define MAX_SIZE 32
#define MAX_PATH_SIZE 1024

#define NUM_DIRECT 1 << 2

struct timestamp{
    unsigned long int ctime; // When the particular inode was changed. Stored in Epoch
	unsigned long int mtime; // when the file contents were modified Stored in Epoch
	unsigned long int atime; // when the file was accessed. Stored in Epoch
};

struct vrfs_stat{
    int inode_num;
    int size;
    struct timestamp tstamp;
    int type;
    int direct[NUM_DIRECT];
};

struct dentry;

char rootdirname[MAX_SIZE];
char current_working_directory[MAX_PATH_SIZE];
int rootinode;
struct dentry{
    char name[MAX_SIZE];
    int inode_num;
};

/* File Operations */
int create(char *filename);
bool read(char *filename, char *data, rsize_t size);
bool write(char *filename, char *data, rsize_t size);
int rm_file(char* filename);
struct vrfs_stat *stat(char *filename);

/*Directory Operations*/
char* present_working_directory();
int make_directory(char *dirname);
int remove_directory(char* dirname);
struct dentry * read_dir(char *dirname, int* size);
int change_directory(char *dirname);

int make_rfs(char *username);

#endif /* VRFS_VRFS_H_ */
