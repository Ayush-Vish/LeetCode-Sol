#include <iostream>
#include <memory>
#include <string>
using namespace std;

class IDatabaseConnection{
      public:
      virtual void connect(const string& connectionString) = 0 ;
      virtual void executeQuery(const string& query) = 0 ;
      virtual ~IDatabaseConnection() = default;
};
class MySQLConnection: public IDatabaseConnection{
      public:
      void connect(const string& connectionString) override{
            cout << "Connected to MySQL with connection string: " << connectionString << endl;
      }
      void executeQuery(const string& query) override{
            cout << "Executing query: " << query << endl;
      }
};
class MongoDBConnection: public IDatabaseConnection{
      public:
      void connect(const string& connectionString) override{
            cout << "Connected to MongoDB with connection string: " << connectionString << endl;
      }
      void executeQuery(const string& query) override{
            cout << "Executing query: " << query << endl;
      }
};
class IDatabaseFactory{
      public:
      virtual unique_ptr<IDatabaseConnection>createConnection() = 0;
      virtual ~IDatabaseFactory() = default;
};

class MySQLFactory: public IDatabaseFactory{
      public:
      unique_ptr<IDatabaseConnection>createConnection() override{
            return make_unique<MySQLConnection>();
      }
};
class MongoDBFactory: public IDatabaseFactory{
      public:
      unique_ptr<IDatabaseConnection>createConnection() override{
            return make_unique<MongoDBConnection>();
      }
};
int main(){
      string dbType = "mongo";
      unique_ptr<IDatabaseFactory> dbFactory ;

      if(dbType == "mongo") {
            dbFactory = make_unique<MongoDBFactory>();
      }else if(dbType == "mysql") {
            dbFactory = make_unique<MySQLFactory>();
      }

      unique_ptr<IDatabaseConnection> connection = dbFactory->createConnection();
      connection->connect("localhost");
      connection->executeQuery("SELECT * FROM users");
      return 0;

}
