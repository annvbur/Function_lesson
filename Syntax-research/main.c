//
//  main.c
//  Syntax-research
//
//  Created by Mac on 19.10.14.
//  Copyright (c) 2014 Mac. All rights reserved.
//

#include <stdio.h>
#include <math.h>
// все декларации моих функций
float distance_between_points(float x1, float y1, float x2, float y2);
int if_point_in_circle(float x1, float y1, float x2, float y2, float radius);
int count_similar_digits(int digit);
void min_or_max_digit(int number);
int part_of_cvart(float x, float y);

int main(int argc, const char * argv[]) {
    float d = distance_between_points(0, 5, 2, 8);// расстояние между двумя точками ищем
    
    printf("\nDistance = %f\n", d);
    
    
    int isPointinCircle = if_point_in_circle(6, 8, 5, 10, 3);//попадает ли данная точка в окружность
    printf("Point in circle %d\n", isPointinCircle);
    
    int How_many_digits = count_similar_digits(907);// смотрим сколько одинаковых цифр в трехзначном числе
    
    printf("How_many_digits %d \n", How_many_digits);//смотрим сколько одинаковых цифр в трехзначном числе
    count_similar_digits(678);
    
    
    min_or_max_digit (915);
    min_or_max_digit (100);
    min_or_max_digit (544);
    

    printf("Part of graph = %d\n", part_of_cvart(-4, -3));// определяем в какой квадрант попадает точка по координатам.Если точка лежит на оси - мы говорим это.
    printf("Part of graph = %d\n", part_of_cvart(0, 0));
    printf("Part of graph = %d\n", part_of_cvart(-4, 8));
    printf("Part of graph = %d\n", part_of_cvart(9, -1));
    
    int q = part_of_cvart(0, 1);
    if(q){
      printf("Part of graph = %d\n", q);
    }
    q = part_of_cvart(12, 0);
    if(q){
        printf("Part of graph = %d\n", q);
    }
    
    return 0;
    
}

float distance_between_points(float x1, float y1, float x2, float y2){// расстояне между точками
    
    
    float d = sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
    return d;
}

int if_point_in_circle(float x1, float y1, float x2, float y2, float radius){//попадает ли чтока в окружность или нет
    
    float r1 = distance_between_points(x1, y1, x2, y2);
    
    int result = 0;
    
    if (r1<=radius){
        printf("\npoint in the circle\n");
        result = 1;
    }else{
        printf("\npoint not in the circle\n");
    }
    
    return result;
}

int count_similar_digits(int digit){// кол-во один-х цифр в числе
    int result = 0;
    
    int d1 = digit %10;
    int d2 = (digit /10) %10;
    int d3 = (digit / 100)%10;
    printf("\nThefirst %d, Second %d, Thirt %d\n",d1, d2, d3);
    
    if (d1==d2 && d2==d3){
        result = 3;
    }else if((d1==d2)||(d2==d3)||(d1==d3)){
        result = 2;
    }
    
    return result;
}
void min_or_max_digit(int number){//макс и мин числа в трехзначнм числе
    
    int d1 = number %10;
    int d2 = (number /10) %10;
    int d3 = (number / 100)%10;
    int max = 0;
    int min = 0;
    printf("\nThefirst %d, Second %d, Thirt %d\n",d1, d2, d3);
    
    if (d1>=d2 && d1>=d3){
        max = d1;
    }else if(d2>=d1 && d2>=d3){
        max = d2;
    }else{
        max = d3;
    };
    
    if(d1<=d2 && d1<=d3){
        min = d1;
    }else if(d2<=d1 && d2<=d3){
        min = d2;
    }else{
        min = d3;
    };
    printf("min %d, max %d\n", min, max);
}


int part_of_cvart(float x, float y){//определяем квадрант по координатам точки
    int result = 0;
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    
    if (x != 0 && y == 0){
        printf("Point lies on x\n");
    }else if (x == 0 && y != 0){
        printf("Point lies on y\n");
    }
    
    if (x > 0 && y > 0){
        result = 1;
    }else if (x > 0 && y <0){
        result = 2;
    }else if (x < 0 && y < 0){
        result = 3;
    }else if (x < 0 && y > 0){
        result = 4;
    }
    
    return result;
}
