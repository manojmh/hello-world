#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_OF_SUITS 4
#define NUM_OF_VALUES 13
#define NUM_OF_CARDS_IN_DECK 52

typedef enum {
    SPADE = 0,
    HEART,
    DIAMOND,
    CLUB
} SUIT;

typedef enum {
    TRUE,
    FALSE
} BOOLEAN;

typedef enum {
    TWO = 0,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} VALUE;

typedef struct Card {
    SUIT suit;
    VALUE value;
} Card;

void shuffle(Card [], int, int);
void dealTheCards(Card [], Card [], Card [], Card [], Card []);
void rearrangeCards(Card []);
int calculateNumOfSets(Card []);
int calculateNumOfSequence(Card []);
void displayCards(Card [], int);
int calculateScore(Card[]);
int getMaxScore(Card [], Card [], Card [], Card []);


void main() {
    SUIT suits[] = {SPADE, HEART, DIAMOND, CLUB};
    VALUE values[] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
    Card deck[NUM_OF_CARDS_IN_DECK];
    Card north[NUM_OF_VALUES], east[NUM_OF_VALUES], south[NUM_OF_VALUES], west[NUM_OF_VALUES];
    int i, j, k;
    int firstIndex, lastIndex;
    scanf("%d", &firstIndex);
    scanf("%d", &lastIndex);

    for (i = 0, k = 0; i < NUM_OF_SUITS; i++)
        for (j = 0; j < NUM_OF_VALUES; j++, k++) {
            deck[k].suit = suits[i];
            deck[k].value = values[j];
        }

    //displayCards(deck,52);
    for (i = lastIndex, j = firstIndex; i < NUM_OF_CARDS_IN_DECK; i++, j++) {
  	shuffle(deck, j, i);
     }
	//printf("-----------\n");
   // displayCards(deck,52);


    dealTheCards(deck, north, east, south, west);
    
    displayCards(north, NUM_OF_VALUES);
    displayCards(east, NUM_OF_VALUES);
    displayCards(south, NUM_OF_VALUES);
    displayCards(west, NUM_OF_VALUES);


    rearrangeCards(north);
    rearrangeCards(east);
    rearrangeCards(south);
    rearrangeCards(west);
    
    displayCards(north, NUM_OF_VALUES);
    displayCards(east, NUM_OF_VALUES);
    displayCards(south, NUM_OF_VALUES);
    displayCards(west, NUM_OF_VALUES);
    printf("\nSETCOUNT:\t%d,%d,%d,%d", calculateNumOfSets(north), calculateNumOfSets(east), calculateNumOfSets(south), calculateNumOfSets(west));
    printf("\nSEQCOUNT:\t%d,%d,%d,%d", calculateNumOfSequence(north), calculateNumOfSequence(east), calculateNumOfSequence(south), calculateNumOfSequence(west));
    printf("\nMax Score : %d", getMaxScore(north, east, south, west));
}


void displayCards(Card hand[], int numOfCards) {
    int i = 0;
    while (i < numOfCards) {
        if (hand[i].value == TWO)
            printf(" 2");
        else if (hand[i].value == THREE)
            printf(" 3");
        else if (hand[i].value == FOUR)
            printf(" 4");
        else if (hand[i].value == FIVE)
            printf(" 5");
        else if (hand[i].value == SIX)
            printf(" 6");
        else if (hand[i].value == SEVEN)
            printf(" 7");
        else if (hand[i].value == EIGHT)
            printf(" 8");
        else if (hand[i].value == NINE)
            printf(" 9");
        else if (hand[i].value == TEN)
            printf("10");
        else if (hand[i].value == JACK)
            printf("J");
        else if (hand[i].value == QUEEN)
            printf("Q");
        else if (hand[i].value == KING)
            printf("K");
        else if (hand[i].value == ACE)
            printf("A");
        if (hand[i].suit == SPADE) {
            printf("S");
        } else if (hand[i].suit == HEART) {
            printf("H");
        } else if (hand[i].suit == DIAMOND) {
            printf("D");
        } else if (hand[i].suit == CLUB) {
            printf("C");
        }
        printf("    ");
        i++;
    }
    printf("\n");
}


void shuffle(Card deck[],int j, int i)
{
	int a=i-j+1;
	Card temp[a];
	int m,n,k;
	
	for(m=0,n=j;n<=i;m++,n++)
		temp[m]=deck[n];

	for(k=j-1;k>=0;k--,i--)
		deck[i]=deck[k];
	
	for(m=0;m<a;m++)
		deck[m]=temp[m];
	

}


void dealTheCards(Card deck[],Card north[],Card east[],Card south[],Card west[])
{
	int i,j,k,l,m;
	for(i=0,j=0,k=1,l=2,m=3;i<NUM_OF_VALUES;i++,j=j+4,k=k+4,l=l+4,m=m+4)
	{
		north[i]=deck[j];
		east[i]=deck[k];
		south[i]=deck[l];
		west[i]=deck[m];
	}
}

void rearrangeCards(Card manth[13])
{
	Card s[13],h[13],d[13],c[13];
	int temp;
	int i=0,j=0,k=0,l=0,m=0,n=0,x=0,flag=0,swap=0;
	

	while(i<13)
	{
		if(manth[i].suit==SPADE)
		{
			s[j]=manth[i];
			j++;
			i++;
		}
		
		else if(manth[i].suit==HEART)
		{
			h[k]=manth[i];
			k++;
			i++;
		}
		
		else if(manth[i].suit==DIAMOND)
		{
			d[l]=manth[i];
			l++;
			i++;
		}
		
		else if(manth[i].suit==CLUB)
		{
			c[m]=manth[i];
			m++;
			i++;
		}

	
	}

	int a[13];
	n=0;	
	while(n<j)
	{

	if (s[n].value == TWO)
            a[n]=2;
        else if (s[n].value == THREE)
            a[n]=3;
        else if (s[n].value == FOUR)
            a[n]=4;
        else if (s[n].value == FIVE)
            a[n]=5;
        else if (s[n].value == SIX)
            a[n]=6;
        else if (s[n].value == SEVEN)
            a[n]=7;
        else if (s[n].value == EIGHT)
            a[n]=8;
        else if (s[n].value == NINE)
            a[n]=9;
        else if (s[n].value == TEN)
            a[n]=10;
        else if (s[n].value == JACK)
            a[n]=11;
        else if (s[n].value == QUEEN)
            a[n]=12;
        else if (s[n].value == KING)
            a[n]=13;
        else if (s[n].value == ACE)
            a[n]=14;

	n++;
		
	}

	while(!flag)
	{
		swap=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]<a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=1;
			}
		}
		if(!swap)
		flag=1;
	}
     		
	n=0;	
	while(n<j)
	{

	if (a[n]== 2)
            s[n].value=TWO;
        else if (a[n]== 3)
            s[n].value=THREE;
        else if (a[n]== 4)
            s[n].value=FOUR;
        else if (a[n]== 5)
            s[n].value=FIVE;
        else if (a[n] == 6)
            s[n].value=SIX;
        else if (a[n] == 7)
            s[n].value=SEVEN;
        else if (a[n] == 8)
            s[n].value=EIGHT;
        else if (a[n] == 9)
            s[n].value=NINE;
        else if (a[n] == 10)
            s[n].value=TEN;
        else if (a[n] == 11)
            s[n].value=JACK;
        else if (a[n] == 12)
            s[n].value=QUEEN;
        else if (a[n] == 13)
            s[n].value=KING;
        else if (a[n] == 14)
            s[n].value=ACE;

	n++;
	}


	n=0;	
	while(n<k)
	{

	if (h[n].value == TWO)
            a[n]=2;
        else if (h[n].value == THREE)
            a[n]=3;
        else if (h[n].value == FOUR)
            a[n]=4;
        else if (h[n].value == FIVE)
            a[n]=5;
        else if (h[n].value == SIX)
            a[n]=6;
        else if (h[n].value == SEVEN)
            a[n]=7;
        else if (h[n].value == EIGHT)
            a[n]=8;
        else if (h[n].value == NINE)
            a[n]=9;
        else if (h[n].value == TEN)
            a[n]=10;
        else if (h[n].value == JACK)
            a[n]=11;
        else if (h[n].value == QUEEN)
            a[n]=12;
        else if (h[n].value == KING)
            a[n]=13;
        else if (h[n].value == ACE)
            a[n]=14;

	n++;
		
	}
	swap=0;
	flag=0;
	while(!flag)
	{
		swap=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]<a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=1;
			}
		}
		if(!swap)
		flag=1;
	}
     		
	n=0;	
	while(n<k)
	{

	if (a[n]== 2)
            h[n].value=TWO;
        else if (a[n]== 3)
            h[n].value=THREE;
        else if (a[n]== 4)
            h[n].value=FOUR;
        else if (a[n]== 5)
            h[n].value=FIVE;
        else if (a[n] == 6)
            h[n].value=SIX;
        else if (a[n] == 7)
            h[n].value=SEVEN;
        else if (a[n] == 8)
            h[n].value=EIGHT;
        else if (a[n] == 9)
            h[n].value=NINE;
        else if (a[n] == 10)
            h[n].value=TEN;
        else if (a[n] == 11)
            h[n].value=JACK;
        else if (a[n] == 12)
            h[n].value=QUEEN;
        else if (a[n] == 13)
            h[n].value=KING;
        else if (a[n] == 14)
            h[n].value=ACE;

	n++;
	}
	
	n=0;	
	while(n<l)
	{

	if (d[n].value == TWO)
            a[n]=2;
        else if (d[n].value == THREE)
            a[n]=3;
        else if (d[n].value == FOUR)
            a[n]=4;
        else if (d[n].value == FIVE)
            a[n]=5;
        else if (d[n].value == SIX)
            a[n]=6;
        else if (d[n].value == SEVEN)
            a[n]=7;
        else if (d[n].value == EIGHT)
            a[n]=8;
        else if (d[n].value == NINE)
            a[n]=9;
        else if (d[n].value == TEN)
            a[n]=10;
        else if (d[n].value == JACK)
            a[n]=11;
        else if (d[n].value == QUEEN)
            a[n]=12;
        else if (d[n].value == KING)
            a[n]=13;
        else if (d[n].value == ACE)
            a[n]=14;

	n++;
		
	}
	swap=0;
	flag=0;
	while(!flag)
	{
		swap=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]<a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=1;
			}
		}
		if(!swap)
		flag=1;
	}
     		
	n=0;	
	while(n<l)
	{

	if (a[n]== 2)
            d[n].value=TWO;
        else if (a[n]== 3)
            d[n].value=THREE;
        else if (a[n]== 4)
            d[n].value=FOUR;
        else if (a[n]== 5)
            d[n].value=FIVE;
        else if (a[n] == 6)
            d[n].value=SIX;
        else if (a[n] == 7)
            d[n].value=SEVEN;
        else if (a[n] == 8)
            d[n].value=EIGHT;
        else if (a[n] == 9)
            d[n].value=NINE;
        else if (a[n] == 10)
            d[n].value=TEN;
        else if (a[n] == 11)
            d[n].value=JACK;
        else if (a[n] == 12)
            d[n].value=QUEEN;
        else if (a[n] == 13)
            d[n].value=KING;
        else if (a[n] == 14)
            d[n].value=ACE;

	n++;
	}

	n=0;	
	while(n<m)
	{

	if (c[n].value == TWO)
            a[n]=2;
        else if (c[n].value == THREE)
            a[n]=3;
        else if (c[n].value == FOUR)
            a[n]=4;
        else if (c[n].value == FIVE)
            a[n]=5;
        else if (c[n].value == SIX)
            a[n]=6;
        else if (c[n].value == SEVEN)
            a[n]=7;
        else if (c[n].value == EIGHT)
            a[n]=8;
        else if (c[n].value == NINE)
            a[n]=9;
        else if (c[n].value == TEN)
            a[n]=10;
        else if (c[n].value == JACK)
            a[n]=11;
        else if (c[n].value == QUEEN)
            a[n]=12;
        else if (c[n].value == KING)
            a[n]=13;
        else if (c[n].value == ACE)
            a[n]=14;

	n++;
		
	}
	swap=0;
	flag=0;
	while(!flag)
	{
		swap=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]<a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				swap=1;
			}
		}
		if(!swap)
		flag=1;
	}
     		
	n=0;	
	while(n<m)
	{

	if (a[n]== 2)
            c[n].value=TWO;
        else if (a[n]== 3)
            c[n].value=THREE;
        else if (a[n]== 4)
            c[n].value=FOUR;
        else if (a[n]== 5)
            c[n].value=FIVE;
        else if (a[n] == 6)
            c[n].value=SIX;
        else if (a[n] == 7)
            c[n].value=SEVEN;
        else if (a[n] == 8)
            c[n].value=EIGHT;
        else if (a[n] == 9)
            c[n].value=NINE;
        else if (a[n] == 10)
            c[n].value=TEN;
        else if (a[n] == 11)
            c[n].value=JACK;
        else if (a[n] == 12)
            c[n].value=QUEEN;
        else if (a[n] == 13)
            c[n].value=KING;
        else if (a[n] == 14)
            c[n].value=ACE;

	n++;
	}


	n=0;
	while(n<13)
	{
		for(x=0;x<j;x++,n++)
		manth[n]=s[x];
		
		for(x=0;x<k;x++,n++)
		manth[n]=h[x];
		
		for(x=0;x<l;x++,n++)
		manth[n]=d[x];
		
		for(x=0;x<m;x++,n++)
		manth[n]=c[x];
	
		n++;		
	}



}

int calculateNumOfSets(Card manth1[13])
{
	int i=0,j=0,count=0,set=0,n=0,c=20,b=20;
	int a[13];

	n=0;	
	while(n<13)
	{

	if (manth1[n].value == TWO)
            a[n]=2;
        else if (manth1[n].value == THREE)
            a[n]=3;
        else if (manth1[n].value == FOUR)
            a[n]=4;
        else if (manth1[n].value == FIVE)
            a[n]=5;
        else if (manth1[n].value == SIX)
            a[n]=6;
        else if (manth1[n].value == SEVEN)
            a[n]=7;
        else if (manth1[n].value == EIGHT)
            a[n]=8;
        else if (manth1[n].value == NINE)
            a[n]=9;
        else if (manth1[n].value == TEN)
            a[n]=10;
        else if (manth1[n].value == JACK)
            a[n]=11;
        else if (manth1[n].value == QUEEN)
            a[n]=12;
        else if (manth1[n].value == KING)
            a[n]=13;
        else if (manth1[n].value == ACE)
            a[n]=14;
	n++;
		
	}
	
	for(i=0;i<n;i++)
	{	
		count=0;
		for(j=i;j<n;j++)
		{
			if(c!=a[i])
			{
				if(a[i]==a[j+1])
				{
					b=a[i];
					count++;
				}
			}
		}
		if((count==3)||(count==4))
		set++;
		if(count==4)
		c=b;
	}	

	return(set);

}

int calculateNumOfSequence(Card manth2[13])
{
	int a[13];

	int count=0,n=0;	
	while(n<13)
	{

	if (manth2[n].value == TWO)
            a[n]=2;
        else if (manth2[n].value == THREE)
            a[n]=3;
        else if (manth2[n].value == FOUR)
            a[n]=4;
        else if (manth2[n].value == FIVE)
            a[n]=5;
        else if (manth2[n].value == SIX)
            a[n]=6;
        else if (manth2[n].value == SEVEN)
            a[n]=7;
        else if (manth2[n].value == EIGHT)
            a[n]=8;
        else if (manth2[n].value == NINE)
            a[n]=9;
        else if (manth2[n].value == TEN)
            a[n]=10;
        else if (manth2[n].value == JACK)
            a[n]=11;
        else if (manth2[n].value == QUEEN)
            a[n]=12;
        else if (manth2[n].value == KING)
            a[n]=13;
        else if (manth2[n].value == ACE)
            a[n]=14;
	n++;
		
	}

	n=0;
	while(n<13)
	{
		if((manth2[n].suit==manth2[n+1].suit)&&(manth2[n].suit==manth2[n+2].suit))
		{
			if((a[n]==a[n+1]+1)&&(a[n]==a[n+2]+2))
			{
				count++;
				n=n+3;
			}
			else
				n++;
				
		}
		else
			n++;
	}

	return(count);
	
}

int calculateScore(Card hand[13])
{
	int a=0;
	a=((calculateNumOfSequence(hand))+(calculateNumOfSets(hand)));
	return(a);
}



int getMaxScore(Card north[13], Card east[13], Card south[13], Card west[13])
{
	int n=0,e=0,s=0,w=0;
	int max;
	n=calculateScore(north);
	e=calculateScore(east);
	s=calculateScore(south);
	w=calculateScore(west);
	max=n;
	
	if(e>=max)
	max=e;
	if(s>=max)
	max=s;
	if(w>=max)
	max=w;
	
	return(max);

}


