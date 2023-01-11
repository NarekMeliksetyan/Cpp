#include <iostream>
#include <vector>

class Node
{
public:
  explicit Node(int score_) : score(score_) {}
  int getScore() const { return this->score; }
  int getTotalScore() const { return this->totalScore; }

  void addChild(Node *child)
  {
    this->children.push_back(child);
    child->parent = this;
  }

  void calculateTotalScore()
  {
    this->totalScore = this->score;
    for (auto child : this->children)
    {
      child->calculateTotalScore();
      this->totalScore += child->totalScore;
    }
  }

  void setScore(int newScore)
  {
    int diff = newScore - this->score;
    this->score = newScore;
    this->totalScore += diff;

    Node *root = this->parent;
    while (root)
    {
      root->totalScore += diff;
      root = root->parent;
    }
  }

private:
  int score = 0;
  int totalScore = 0; // new
  std::vector<Node *> children;
  Node *parent = NULL;
};

int main()
{
  auto a = Node(3);
  auto b = Node(5);
  auto c = Node(7);
  auto d = Node(11);
  auto e = Node(13);
  auto f = Node(17);

  a.addChild(&b);
  a.addChild(&c);
  c.addChild(&d);
  c.addChild(&e);
  c.addChild(&f);

  a.calculateTotalScore();
  std::cout << a.getTotalScore() << std::endl;

  d.setScore(42);
  std::cout << d.getTotalScore() << std::endl;
  std::cout << c.getTotalScore() << std::endl;
  std::cout << a.getTotalScore() << std::endl;
}