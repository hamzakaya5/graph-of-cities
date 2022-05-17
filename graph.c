#include <stdio.h>
#include <time.h>

/*------------------variable definitions------------------*/


//char array will hold the names of the cities
char cityArray[7][10] = {{"prague"},{"helsinki"},{"beijing"},{"tokyo"},{"jakarta"},{"london"},{"newYork"}};	
int passedCities[20];								//holds the distance of the passed cities
int adjMatrix[7][7];							   //adjacency matrix of cities
int breakPoint = 0;								  //used for holding the situation which a city is passed again


/*--------------function prototypes--------------*/


													//takes To city (source and detination) as inputs
int convertCityToNumber(char s[], char d[]);	   //and the index of the cities is found
int searchCity(int s, int d);				      //finds the cities with the
int assignDistances();						     //assigns the distances of the cities to the adjacency matrix
int calculateDistance();						//calculates the distances between typed 2 city


/*-------------main function-------------*/


int main(){
	assignDistances();
	int s, d; 					//source and destination cities
	while(1){
		printf("\nCities:\nprag = 0\nhelsinki = 1\nbeijing = 2\ntokyo = 3\njakarta = 4\nlondon = 5\nnewYork = 6\n\n");
		printf("Enter the number of the first city\n");
		scanf("%d", &s);
		printf("Enter the number of the second city\n");
		scanf("%d", &d);
		printf("\n%s -> ", cityArray[s]);
		searchCity(s, d);
		memset(passedCities, 0, sizeof(passedCities));	//when all the processes is done, it clears the passedCities
	}
}


int searchCity(int x, int y){
	int i = 0, j = 0, z = 0;
	for(i; adjMatrix[x][i] == 0; i++);				//finds the first city connected to itself
	for(z=0; passedCities[z] != 0; z++){			//adds the distance to the array of passed cities
	
		//if any of passed city is equals to the current city (adjMAtrix), it goes to the one next city
		if( passedCities[z] == adjMatrix[x][i] ){
			breakPoint = 1;
			for(i; adjMatrix[x][i+1] == 0; i++);
			i++;
			z = 0;
		}
	}
	if( i >= 7 ){							//that statement means, path could not found
		printf("Path could not found");	
		sleep(2);
		system("cls");						//clears screen
		return 0;
	}


	//if breakpoint is 1 that means the current city is passed again and
	// it is not added to the passed cities again
	if(breakPoint == 0){
		for(j; passedCities[j] != 0; j++);
		Sleep(300);
		passedCities[j] = adjMatrix[x][i];
	}else{
		Sleep(300);
		breakPoint = 0;
	}
	x = i;
	
	//if destination address index is equals to the current index of the city, function returns
	//else, prints the city that have been passed
	if(x == y){
		printf("%s", cityArray[i]);
		printf("\nDistance between 2 city = %d km\n", calculateDistance());
		sleep(4);
		system("cls");
		return 0;
	}else{
		printf("%s -> ", cityArray[i]);
		searchCity(x, y);								// function is being called recursively	
	}
	return 0;
}


int calculateDistance(){
	int a;
	int sum = 0;
	for(a=0; passedCities[a] != 0; a++){
		sum += passedCities[a];
	}
	return sum;
}


int assignDistances(){
	memset(adjMatrix, 0, sizeof(adjMatrix));			//set all values of the array to zero
/*		distance between cities			*/
	adjMatrix[0][1]	= 1845;
	adjMatrix[0][5] = 1246;
	adjMatrix[1][3] = 7815;
	adjMatrix[2][3] = 1303;
	adjMatrix[2][5] = 3132;
	adjMatrix[2][6] = 11550;
	adjMatrix[3][4] = 5782;
	adjMatrix[3][6] = 10838;
	adjMatrix[4][2] = 4616;
	adjMatrix[5][3] = 9566;
	adjMatrix[6][5] = 55667;
	return 0;
};


