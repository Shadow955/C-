#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"base_struct.h"
#include<string.h>
struct record* rec_head;
FILE* infile;
FILE* outfile;
int openfile() {
	infile = fopen("source.txt", "a");
	if (infile == NULL)
	{
		printf("文件打开失败！请检查源文件！");
		return 0;
	}
	else
		printf("文件打开成功！");
}
void read_and_link() {
	rec_head = (record*)malloc(sizeof(record));		//建立头节点
	rec_head->next = NULL;
	record* rec_this = rec_head;						//建立当前节点
	record* rec_temp = (record*)malloc(sizeof(record));
	while (1)
	{
		if (fscanf(infile, "%ld %s %d %d"
			, &(rec_temp->num_check)
			, (rec_temp->pat.name_pat)
			, &(rec_temp->pat.age)
			, &(rec_temp->pat.tag_pat)) == EOF)
		{
			free(rec_temp);
			break;
		}
		else
		{
			fscanf(infile, "%s %d %d %ld"
				, (rec_temp->doc.name_doc)
				, &(rec_temp->doc.level)
				, &(rec_temp->doc.sub)
				, &(rec_temp->doc.num_work));
			fscanf(infile, "%s", rec_temp->out_doc);
			//fscanf(infile, "%s", rec_temp->tre.che.type[0]);
			int i = 0, j = 0;
			while (strcmp("over", rec_temp->tre.che.type[i]) != 0)
			{
				fscanf(infile, "%d", rec_temp->tre.che.cost_term);
				i++;
			}
			while (strcmp("over", rec_temp->tre.pil.name_pill[j] )!= 0)
			{
				fscanf(infile, "%s %d %d"
					, rec_temp->tre.pil.name_pill[j]
					, &(rec_temp->tre.pil.cost_perpill)
					, &(rec_temp->tre.pil.num_pill));
				j++;
			}
			fscanf(infile, "%d %d %d"
				, &(rec_temp->tre.hos.time_start)
				, &(rec_temp->tre.hos.time_end)
				, &rec_temp->tre.hos.deposit);
		}
	}
	rec_temp->next = NULL;
	rec_this->next = rec_temp;
	rec_this = rec_temp;
	fclose(infile);
}