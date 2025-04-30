#include <stdio.h>
#include <string.h>

/*
//1.12.1
int media(int idade_total, int quantidade){
    float result = idade_total/quantidade;
    return result;
}
int main(){
    int age;
    int quantidade = 0;
    float result;
    int idade_total=0;
    scanf("%d", &age);
    while (age>0){
        quantidade=quantidade+1;
        idade_total=idade_total+age;
        scanf("%d", &age);
    }
    result=media(idade_total,quantidade);
    printf("%.2f",result);
    
    return 0;
}
*/


/*
//1.12.2
float higher(float height,float higherHeight){
    if (height>higherHeight){
        higherHeight=height;
    }
    return higherHeight;
}

float smaller(float height, float smallerHeight){
    if (height<smallerHeight){
        smallerHeight=height;
    }
    return smallerHeight;
}

float woman (float total, int quantity){
    if (quantity > 0) {
        return total / quantity; 
    }
    return 0.0;
}

int main(){
    float height;
    char gener[20];
    int quantityMen = 0;
    float higherHeight=0.00;
    float smallerHeight=100.00;
    float averange =0.00;
    float total=0.00;
    int quantity=0;

    for (int i=0; i<5; i++){
        scanf("%f", &height);
        scanf("%s", gener);

        if (strcmp(gener,"masculino")==0){
            quantityMen++;
        }

        higherHeight = higher(height,higherHeight);
        smallerHeight = smaller(height,smallerHeight);

        if (strcmp(gener,"feminino")==0){
            total+=height;
            quantity++;
        }
        averange = woman(total,quantity);
    }

    printf("Mens Quantities=%d,higher=%.2f,smaller=%.2f,womans averange=%.2f\n",quantityMen,higherHeight,smallerHeight,averange);

    return 0;
}
*/

/*
//1.12.3
float celsius (int value) {
    return ((5.0/9.0)*(value-32));
}
int main(){
    int ferenheit;
    for (ferenheit=50; ferenheit<150; ferenheit++){
        printf("%.2f\n",celsius(ferenheit));
    }
    return 0;
}
*/


/*
//1.12.4
float profit (float buy, float sell){
    return (((sell*100)/buy)-100.00);
}

int main(){
    char name[50];
    float buy = 0.0;
    float sell = 0.0;
    int twenty = 0;
    int tenTwenty = 0;
    int ten = 0;
    float lucro = 0.0;
    float totalBuy = 0.0;
    float totalSell = 0.0;
    float lucroProfit = 0.0;

    scanf(" %s", name);

    while (strcmp(name,"exit")!=0){
        scanf(" %f", &buy);
        scanf(" %f", &sell);

        lucroProfit = profit(buy,sell);

        if (lucroProfit > 20) {
            twenty++;
        } else if (lucroProfit < 10) {
            ten++;
        } else if (10 <= lucroProfit && lucroProfit <= 20.0) {
            tenTwenty++;
        }
        

        lucro+= (sell - buy);
        totalBuy+= buy;
        totalSell+= sell;

        printf("Lucro: %.2f%%\n", lucroProfit);

        scanf(" %s", name);
    }
    printf(" Small than ten: %d\n between ten and twenty: %d\n bigger than twenty: %d\n Total Buy: %.2f\n Total Sell: %.2f\n Profit: %.2f",
        ten,tenTwenty,twenty,totalBuy,totalSell,lucro);
    
    return 0;
}
*/



/* Anotações aula

Vetor de forma precaria
chat vet[4];
vet[0]="I"
vet[1]="F"
vet[2]="E"
vet[3]="S"


*/