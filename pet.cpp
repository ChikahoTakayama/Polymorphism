// Pet sample

#include <iostream> // cout, endl を使うため
#include <string> // string を使うため

using namespace std; // これを書くと std::cout と書かずに cout と省略できる

class Pet // クラス Pet を定義する
{
public: // 以下のメンバー変数やメソッドを公開する
    virtual string GetAngry() = 0; // 抽象メソッド
    virtual string rejoice() = 0; 
    virtual ~Pet() {} // デストラクタ: delete で呼ばれる
};

class Cat : public Pet // スーパークラスが Pet であるようなクラス Cat を定義する
{
public:
    virtual string GetAngry() // C++ ではメソッドに virtual とつけるとポリモーフィズムが利くようになる
    {
        return "ネコがひっかく、毛を逆立てる";
    }
  virtual string rejoice() // C++ ではメソッドに virtual とつけるとポリモーフィズムが利くようになる
    {
        return "ネコが喉を鳴らす";
    }
};


class Dog : public Pet
{
public:
    virtual string GetAngry()
    {
        return "イヌがほえる、噛む";
    }
      virtual string rejoice()
    {
        return "イヌが尻尾を振る";
    }
};

int main()
{
    Pet* pet = new Cat(); // Cat クラスのインスタンス(実体)を新規作成し，ポインタ変数 pet に代入する
    cout << pet->GetAngry() << endl; // C言語風に書くと printf("%s\n", pet->GetAngry());
    cout << pet->rejoice() << endl;
    delete pet; // C++ ではオブジェクトを使い終わったら必ず delete する

    pet = new Dog();
    cout << pet->GetAngry() << endl; // C言語風に書くと printf("%s\n", pet->GetAngry());
     cout << pet->rejoice() << endl;
    delete pet;

    return 0;
}
