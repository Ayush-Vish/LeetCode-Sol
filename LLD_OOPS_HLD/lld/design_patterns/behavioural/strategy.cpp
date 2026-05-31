class IPaymentStragety{
public:
      virtual void pay(int amount) = 0 ;
      virtual ~IPaymentStragety() = default;
};    
class StripPaymentStragety : public IPaymentStragety{
public:
      void pay(int amount) override {
            cout << "Processing strip payment of amount " << amount << endl;
      }
};

class PayPalPaymentStragety : public IPaymentStragety{
public:
      void pay(int amount) override {
            cout << "Processing PayPal payment of amount " << amount << endl;
      }
};




class PaymentProcessor {
private:
      unique_ptr<IPaymentStragety> paymentStragety;

public:
      void setStragety(unique_ptr<IPaymentStragety> paymentStragety){
            this->paymentStragety = move(paymentStragety);
      }
      void pay(int amount){
            if(this->paymentStragety) {
                  paymentStragety->pay(amount);
            }else{
                  cout << "No Payment Stragety is Selected  "<< endl;
            }
      }     
};
int main() {
      
      unique_ptr<PaymentProcessor> p = make_unique<PaymentProcessor>();


      unique_ptr<IPaymentStragety> strip = make_unique<StripPaymentStragety>();

      p->setStragety(move(strip));
      p->pay(222);


}
