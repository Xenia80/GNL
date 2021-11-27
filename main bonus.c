int        fd_1;
    char    *line;

    fd_1 = open("text.txt", O_RDONLY);
    //fd_2 = open("text.txt", O_RDONLY);
    line = get_next_line(fd_1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd_1);
    free(line);
    line = get_next_line(fd_1);
    free(line);
    close (fd_1);
    return (0);


    int    main(void)
{
    int        fd_1;
    char    *line;

    fd_1 = open("text.txt", O_RDONLY);
    //fd_2 = open("text.txt", O_RDONLY);
    line = get_next_line(fd_1);
    while (line)
    {
        printf("%s", line);
        line = get_next_line(fd_1);
        free(line);
    }
    //printf("%s", line);
    close(fd_1);
    //close(fd_2);
    return (0);
}
