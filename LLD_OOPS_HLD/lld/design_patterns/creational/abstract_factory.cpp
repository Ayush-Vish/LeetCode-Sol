class Button {
      public:
      virtual void paint() = 0;
      virtual ~Button() = default;
};
class CheckBox {
      public:
      virtual void render()= 0;
      virtual ~CheckBox() =default;
};

class WindowsButton :public Button {
      public:
      void paint()override{
            cout << "this is Windows Button"
      }      
};

class MacButton:public Button {
      public:
      void paint() override{
            cout << "this is Mac Button" << endl;
      }
};


class MacCheckBox:public CheckBox {
      public:
      void render() override{
            cout << "this is Mac CheckBox" << endl;
      }
};

class WindowsCheckBox:public CheckBox {
      public:
      void render() override{
            cout << "this is Windows CheckBox" << endl;
      }
};

class GUIFactory {
      public:
      virtual unique_ptr<Button>createButton() = 0;
      virtual unique_ptr<CheckBox>createCheckBox() = 0;
      virtual ~GUIFactory() = default;
};

class WindowsFactory:public GUIFactory{
      public:
      unique_ptr<Button>createButton()override{
            return make_unique<WindowsButton>();
      }
      unique_ptr<CheckBox>createCheckBox()override{
            return make_unique<WindowsCheckBox>();
      }
      ~WindowsFactory() override = default;
};

class MacFactory:public GUIFactory{
      public:
      unique_ptr<Button>createButton()override{
            return make_unique<MacButton>();
      }
      unique_ptr<CheckBox>createCheckBox()override{
            return make_unique<MacCheckBox>();
      }
      ~MacFactory() override = default;
};

int main(){
      unique_ptr<GUIFactory>factory = make_unique<WindowsFactory>();
      unique_ptr<Button>button = factory->createButton();
      unique_ptr<CheckBox>checkBox = factory->createCheckBox();
      button->paint();
      checkBox->render();
      return 0;
}
      
