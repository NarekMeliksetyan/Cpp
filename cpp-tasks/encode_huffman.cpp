/*
 * Условие:
 *    По данной непустой строке 𝑠 длины не более 10^4, состоящей из строчных
 *    букв латинского алфавита, постройте оптимальный беспрефиксный код.
 *    В первой строке выведите количество различных букв 𝑘,
 *    встречающихся в строке, и размер получившейся закодированной строки.
 *    В следующих 𝑘 строках запишите коды букв в формате "letter: code".
 *    В последней строке выведите закодированную строку.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <memory>

using namespace std;

struct Node
{
    Node(char ch, unsigned int freq,
         shared_ptr<Node> left_node = nullptr,
         shared_ptr<Node> right_node = nullptr)
        : frequency(freq), letter(ch), left(left_node), right(right_node) {}

    shared_ptr<Node> left;
    shared_ptr<Node> right;
    const unsigned int frequency;
    const char letter;

    struct CompareNode
    {
        bool operator()(const shared_ptr<Node> &e1, const shared_ptr<Node> &e2) const
        {
            return e1->frequency > e2->frequency;
        }
    };
};

void make_code_table(const shared_ptr<Node> &node,
                     unordered_map<char, string> &map, string path = string())
{
    if (node->letter != 0)
    {
        map.insert(pair<char, string>(node->letter, path));
        return;
    }
    make_code_table(node->left, map, path + "0");
    make_code_table(node->right, map, path + "1");
}

int main()
{
    string line;
    getline(cin, line);
    unordered_map<char, unsigned int> character_map;
    for (auto ch : line)
    {
        if (character_map.find(ch) != character_map.end())
            ++character_map.at(ch);
        else
            character_map.insert(pair<char, unsigned int>(ch, 1));
    }

    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, Node::CompareNode> letters;
    for (auto elem : character_map)
    {
        auto node = make_shared<Node>(Node(elem.first, elem.second));
        letters.push(node);
    }
    while (letters.size() > 1)
    {
        auto node1 = make_shared<Node>(*letters.top());
        letters.pop();
        auto node2 = make_shared<Node>(*letters.top());
        letters.pop();
        if (node1->frequency < node2->frequency)
        {
            auto new_node = Node(0, node1->frequency + node2->frequency, node1, node2);
            auto node = make_shared<Node>(new_node);
            letters.push(node);
        }
        else
        {
            auto new_node = Node(0, node1->frequency + node2->frequency, node2, node1);
            auto node = make_shared<Node>(new_node);
            letters.push(node);
        }
    }
    unordered_map<char, string> haffman_map;
    if (character_map.size() == 1)
        haffman_map.insert(pair<char, string>((*character_map.begin()).first, "1"));
    else
        make_code_table(letters.top(), haffman_map);
    string code_string;
    for (auto ch : line)
        code_string += haffman_map.at(ch);
    cout << haffman_map.size() << " " << code_string.length() << endl;
    for (auto elem : haffman_map)
        cout << elem.first << ": " << elem.second << endl;
    cout << code_string << endl;
    return 0;
}
