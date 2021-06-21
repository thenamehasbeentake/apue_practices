#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#define APUE_TYPE_SIZE 30
#define APUE_DESCRIBE_SIZE 200

#define print_sysconf(IN)  do { \
printf("sysconf(%s) = %ld\t \tdescribe: %s\n",(IN)->type,  \
    sysconf((IN)->value), (IN)->describe);    \
} while(0);


#define print_pathconf(IN, CBK, APUE_FILEPATH)  do { \
printf("sysconf(%s) = %ld\t \tdescribe: %s\n",(IN)->type,  \
    CBK(APUE_FILEPATH, (IN)->value), (IN)->describe);    \
} while(0);

struct st_sysconf{
    int value;
    char type[APUE_TYPE_SIZE];
    char describe[APUE_DESCRIBE_SIZE];
};

// no file or directory limit that can change
static struct st_sysconf stsyscf[] = {
    {_SC_ARG_MAX, "_SC_ARG_MAX", ""},
    {_SC_CHILD_MAX, "_SC_CHILD_MAX", ""},
    {_SC_HOST_NAME_MAX, "_SC_HOST_NAME_MAX", ""},
    {_SC_LOGIN_NAME_MAX, "_SC_LOGIN_NAME_MAX", ""},
    {_SC_NGROUPS_MAX, "_SC_NGROUPS_MAX", ""},
    {_SC_CLK_TCK, "_SC_CLK_TCK", ""},
    {_SC_OPEN_MAX, "_SC_OPEN_MAX", "The maximum number of files that a process can have open at "
        "any time.  Must not be less than _POSIX_OPEN_MAX (20)."},
    {_SC_PAGESIZE, "_SC_PAGESIZE", "Size of a page in bytes.  Must not be less"
        " than 1.  (Some systems use PAGE_SIZE instead.)"},
    {_SC_RE_DUP_MAX, "_SC_RE_DUP_MAX", ""},
    {_SC_STREAM_MAX, "_SC_STREAM_MAX", ""},
    {_SC_SYMLOOP_MAX, "_SC_SYMLOOP_MAX", ""},
    {_SC_TTY_NAME_MAX, "_SC_TTY_NAME_MAX", ""},
    {_SC_TZNAME_MAX, "_SC_TZNAME_MAX", ""},
    {_SC_VERSION, "_SC_VERSION", ""},

    {_SC_BC_BASE_MAX, "_SC_BC_BASE_MAX", ""},
    {_SC_BC_DIM_MAX, "_SC_BC_DIM_MAX", ""},
    {_SC_BC_SCALE_MAX, "_SC_BC_SCALE_MAX", ""},
    {_SC_BC_STRING_MAX, "_SC_BC_STRING_MAX", ""},
    {_SC_COLL_WEIGHTS_MAX, "_SC_COLL_WEIGHTS_MAX", ""},
    {_SC_LINE_MAX, "_SC_LINE_MAX", ""},
    {_SC_RE_DUP_MAX, "_SC_RE_DUP_MAX", ""},
    {_SC_2_VERSION, "_SC_2_VERSION", ""},
    {_SC_2_C_DEV, "_SC_2_C_DEV", ""},
    {_SC_2_FORT_DEV, "_SC_2_FORT_DEV", ""},
    {_SC_2_FORT_RUN, "_SC_2_FORT_RUN", ""},
    {_SC_2_LOCALEDEF, "_SC_2_LOCALEDEF", ""},
    {_SC_2_SW_DEV, "_SC_2_SW_DEV", ""},
    {_SC_PHYS_PAGES, "_SC_PHYS_PAGES", "The number of pages of physical memory. "
        " Note that it is possible for the product of this value and the value of _SC_PAGESIZE to overflow."},
// _SC_PHYS_PAGES * _SC_PAGESIZE = physical memory
// 1073130 * 4096 B = 4.GB
    {_SC_AVPHYS_PAGES, "_SC_AVPHYS_PAGES", "The number of currently available pages of physical memory."},
// _SC_AVPHYS_PAGES change dynamic
    {_SC_NPROCESSORS_CONF, "_SC_NPROCESSORS_CONF", "The number of "
        "processors configured.  See also get_nprocs_conf(3)"},
    {_SC_NPROCESSORS_ONLN, "_SC_NPROCESSORS_ONLN", "The number of processors "
        "currently online (available).  See also get_nprocs_conf(3)"},


    {_SC_GETGR_R_SIZE_MAX, "_SC_GETGR_R_SIZE_MAX", " "},
};


// pathconf
static struct st_sysconf stpathconf[] = {
    {_PC_LINK_MAX, "_PC_LINK_MAX", ""},
    {_PC_MAX_CANON, "_PC_MAX_CANON", ""},
    {_PC_MAX_INPUT, "_PC_MAX_INPUT", ""},
    {_PC_NAME_MAX, "_PC_NAME_MAX", ""},
    {_PC_PATH_MAX, "_PC_PATH_MAX", ""},
    {_PC_PIPE_BUF, "_PC_PIPE_BUF", ""},
    {_PC_CHOWN_RESTRICTED, "_PC_CHOWN_RESTRICTED", ""},
    {_PC_NO_TRUNC, "_PC_NO_TRUNC", ""},
    {_PC_VDISABLE, "_PC_VDISABLE", ""},
};

// sysconf no errno
void test_sysconf(struct st_sysconf* stcf, int st_size)
{
    for (int i = 0 ; i < st_size; i++) {
        print_sysconf(&stcf[i]);
    }
    return;
}


// sysconf no errno
void test_pathconf(struct st_sysconf* stcf, int st_size)
{
    for (int i = 0 ; i < st_size; i++) {
        // print_pathconf(&stcf[i], pathconf, "/");
        // print_pathconf(&stcf[i], pathconf, "/mnt/glu");
        print_pathconf(&stcf[i], pathconf, "/mnt/sdd/ec-brick2/file");
    }
    return;
}

// sysconf no errno
void test_fpathconf(struct st_sysconf* stcf, int st_size)
{
    for (int i = 0 ; i < st_size; i++) {
        print_pathconf(&stcf[i], fpathconf, STDIN_FILENO);
    }
    return;
}

int main()
{
    // test_sysconf(stsyscf, sizeof(stsyscf) / sizeof(struct st_sysconf));
    // printf("\n\n\n");
    // test_pathconf(stpathconf, sizeof(stpathconf) / sizeof(struct st_sysconf));
    // printf("\n\n\n");
    // test_fpathconf(stpathconf, sizeof(stpathconf) / sizeof(struct st_sysconf));
    
    // printf("_POSIX_C_SOURCE = %ld\n",_POSIX_C_SOURCE);
    // printf("_XOPEN_SOURCE = %ld\n",_XOPEN_SOURCE);
    // printf("_GNU_SOURCE = %ld\n",_GNU_SOURCE);

    return 0;
}

