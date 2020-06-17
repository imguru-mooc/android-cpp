#if 1
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.7

typedef struct 
{
	int kor, eng;
	int total;
	double aver;
	void input();
	void calc();
	void output();
} ST;

int main()
{
	ST s;
	s.input();
	s.calc();
	s.output();

	return 0;
}

void ST::input()
{
	scanf("%d %d", &kor, &eng);
}

void ST::calc()
{
	total = kor + eng;
	aver = total/2.;
}

void ST::output()
{
	printf("%8d %8d %8d %5.2lf\n", kor, eng, total, aver );
}
#endif
#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.6

typedef struct
{
	int kor, eng;
	int total;
	double aver;
} ST;

void input( ST *s );
void calc( ST *s );
void output( ST *s );

int main()
{
	ST s;
	input( &s );
	calc( &s );
	output( &s );

	return 0;
}

void input( ST *s )
{
	scanf("%d %d", &s->kor, &s->eng);
}

void calc( ST *s )
{
	s->total = s->kor + s->eng;
	s->aver = s->total/2.;
}

void output( ST *s )
{
	printf("%8d %8d %8d %5.2lf\n", s->kor, s->eng, s->total, s->aver );
}
#endif

#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.5

typedef struct
{
	int kor, eng, math;
	int total;
	double aver;
} ST;

void input( ST *s );
void calc( ST *s );
void output( ST *s );

int main()
{
	ST s;
	input( &s );
	calc( &s );
	output( &s );

	return 0;
}

void input( ST *s )
{
	scanf("%d %d %d", &s->kor, &s->eng, &s->math);
}

void calc( ST *s )
{
	s->total = s->kor + s->eng + s->math;
	s->aver = s->total/3.;
}

void output( ST *s )
{
	printf("%8d %8d %8d %8d %5.2lf\n", s->kor, s->eng, s->math, s->total, s->aver );
}
#endif

#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.4

void input( int *kor, int *eng, int *math);
void calc( int kor, int eng, int math, int *total, double *aver );
void output( int kor, int eng, int math, int total, double aver );

int main()
{
	int kor, eng, math;
	int total;
	double aver;

	input( &kor, &eng, &math );
	calc( kor, eng, math, &total, &aver );
	output(kor, eng, math, total, aver );

	return 0;
}

void input( int *kor, int *eng, int *math)
{
	scanf("%d %d %d", kor, eng, math);
}

void calc( int kor, int eng, int math, int *total, double *aver )
{
	*total = kor + eng + math;
	*aver = *total/3.;
}

void output( int kor, int eng, int math, int total, double aver )
{
	printf("%8d %8d %8d %8d %5.2lf\n", kor, eng, math, total, aver );
}
#endif

#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.3

void input( int *kor, int *eng);
void calc( int kor, int eng, int *total, double *aver );
void output( int kor, int eng, int total, double aver );

int main()
{
	int kor, eng;
	int total;
	double aver;

	input( &kor, &eng );
	calc( kor, eng, &total, &aver );
	output(kor, eng, total, aver );

	return 0;
}

void input( int *kor, int *eng)
{
	scanf("%d %d", kor, eng );
}

void calc( int kor, int eng, int *total, double *aver )
{
	*total = kor + eng;
	*aver = *total/2.;
}

void output( int kor, int eng, int total, double aver )
{
	printf("%8d %8d %8d %5.2lf\n", kor, eng, total, aver );
}
#endif

#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.2

void input( int *kor, int *eng)
{
	scanf("%d %d", kor, eng );
}

void calc( int kor, int eng, int *total, double *aver )
{
	*total = kor + eng;
	*aver = *total/2.;
}

void output( int kor, int eng, int total, double aver )
{
	printf("%8d %8d %8d %5.2lf\n", kor, eng, total, aver );
}

int main()
{
	int kor, eng;
	int total;
	double aver;

	input( &kor, &eng );
	calc( kor, eng, &total, &aver );
	output(kor, eng, total, aver );

	return 0;
}
#endif


#if 0
#include <stdio.h>
// 간단한 성적 처리 프로그램
// ver 0.1
int main()
{
	int kor, eng;
	int total;
	double aver;

	scanf("%d %d", &kor, &eng );
	total = kor + eng;
	aver = total/2.;

	printf("%8d %8d %8d %5.2lf\n", kor, eng, total, aver );
	return 0;
}
#endif
