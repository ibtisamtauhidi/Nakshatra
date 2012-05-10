void
initTime(void) {
	time_t x;
	x=time(&x); // unit: sec
	currentTime = x/60;
}
void 
incrTime(void){
	time_t x;
	time_t appTime;
	x=time(&x); // unit: sec
	switch(timeRate) {
		case 0:
			if(fastForward==1) {
				appTime = currentTime*60;
				break;
			} else if(fastForward==0) {
				appTime = x;
				currentTime = x/60;
				break;
			}
		case 1:
			currentTime+=130;	
			appTime = currentTime*60;
			break;
		case 2:
			currentTime+=400;	
			appTime = currentTime*60;
			break;
		case 3:
			currentTime+=625;	
			appTime = currentTime*60;
			break;
		case 4:
			currentTime+=1250;	
			appTime = currentTime*60;
			break;
		case 5:
			currentTime+=2500;	
			appTime = currentTime*60;
			break;
		case 6:
			currentTime+=5000;	
			appTime = currentTime*60;
			break;
		case 7:
			currentTime+=10000;	
			appTime = currentTime*60;
			break;
		case 8:
			currentTime+=20000;	
			appTime = currentTime*60;
			break;
		case 9:
			currentTime+=40000;	
			appTime = currentTime*60;
			break;		
		case -1:
			currentTime-=130;	
			appTime = currentTime*60;
			break;
		case -2:
			currentTime-=400;	
			appTime = currentTime*60;
			break;
		case -3:
			currentTime-=625;	
			appTime = currentTime*60;
			break;
		case -4:
			currentTime-=1250;	
			appTime = currentTime*60;
			break;
		case -5:
			currentTime-=2500;	
			appTime = currentTime*60;
			break;
		case -6:
			currentTime-=5000;	
			appTime = currentTime*60;
			break;
		case -7:
			currentTime-=10000;	
			appTime = currentTime*60;
			break;
		case -8:
			currentTime-=20000;	
			appTime = currentTime*60;
			break;
		case -9:
			currentTime-=40000;	
			appTime = currentTime*60;
			break;
	}
	currentTimeString = ctime(&appTime);
}