let cnt =0 ;
let num_retries = 3 ;


function solve( i ,  j ) {
    console.log("Solvinf the Function At Time = " , Date.now());
    if(cnt >=3 ) {
        console.log("Successw" );
    }else{
        if(num_retries > 0 ) {
            num_retries -- ;
            cnt ++ ;

            setTimeout( ()=> solve(i,j),Math.pow(2,cnt)*1000);
        }else{
            console.log("this task if not Succesed adding this in hte Error Queuee/ log")
        }
    }
    
}

solve(0,0);
