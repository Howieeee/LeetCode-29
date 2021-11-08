class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == 0)
            return 0;
        if(dividend == divisor)
            return 1;
        
        int sign =1;
        
        if(dividend <0){
            sign *= -1;
        }
        if(divisor <0){
            sign *= -1;
        }
        
        
        long long l_dividend = abs(dividend);
        long long l_divisor = abs(divisor);
        long long quotient = 0;
        for(int i=31;i>=0;i--){//31bits
            if( (l_divisor<<i) <= l_dividend){
                quotient += (1LL<<i);
                l_dividend -= (l_divisor<<i);
                cout << (1LL<<i) << "   ";
                cout << (l_divisor<<i) << "  i:" << i << endl;
                cout << quotient << " sign:" << sign;
            }
            
        }
        long long ans = quotient*sign;
        
        if(ans > numeric_limits<int>::max())
            ans = numeric_limits<int>::max();
        if(ans < numeric_limits<int>::min())
            ans = numeric_limits<int>::min();
        
        return ans;
        
        
        /*
        if(dividend == 0)
            return 0;
        
        //int_min / -1 ~~ 會超過 int_max
        if(dividend == divisor)
            return 1;
        
        int sign = 1;
        long quotient = 0;
        
        if(divisor<0){
            if(divisor == numeric_limits<int>::min()){
                return 0;
            }else{
                divisor *= -1;
            }
            
            sign *= -1;
        }
        
        if(divisor == 1){//1的情況
            if(dividend == numeric_limits<int>::min() && sign == -1) {//min = -2147483648
                    return numeric_limits<int>::max();
            }else{
                return dividend*sign;
            }
        }
        
        if(dividend<0){
            if(dividend != numeric_limits<int>::min())
                dividend*=-1;
            else{
                dividend += divisor;
                dividend*=-1;
                quotient++;
            }
            sign *= -1;
        }
        
        
        if(dividend < divisor  && quotient ==0){
            //cout << dividend << " " << divisor << endl;
            //cout << "small";
            return 0;
        }
        
       
        
        while(true){//7 4
            dividend -= divisor; //4 1
            if(dividend <0)
                break;
            quotient++;//1 2 
        }
        
        //cout << quotient;
        
        quotient *= sign;
        
        return quotient;*/
    }
};
