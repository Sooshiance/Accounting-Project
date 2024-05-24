#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

class WebPage;
class SearchEngine;

class WebPage
{

public:
    std::string url;
    std::string content;
    WebPage(std::string u, std::string c) : url(u), content(c) {}
};

class InvertedIndex
{

private:
    std::unordered_map<std::string, std::set<int>> index;

public:
    void addPage(int pageId, const std::vector<std::string> &tokens)
    {
        for (const std::string &token : tokens)
        {
            index[token].insert(pageId);
        }
    }

    std::set<int> search(const std::string &token) const
    {
        if (index.find(token) != index.end())
        {
            return index.at(token);
        }
        return std::set<int>();
    }
};

class SearchEngine
{

private:
    std::vector<WebPage> pages;
    InvertedIndex index;
    std::vector<std::string> history;
    // Tokenize content (simple implementation)
    std::vector<std::string> tokenize(const std::string &content)
    {
        std::vector<std::string> tokens;
        std::string token;
        for (char ch : content)
        {
            if (ch == ' ')
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
            }
            else
            {
                token += ch;
            }
        }
        if (!token.empty())
            tokens.push_back(token);
        return tokens;
    }

public:
    void addPage(const WebPage &page)
    {
        pages.push_back(page);
        int pageId = pages.size() - 1;
        index.addPage(pageId, tokenize(page.content));
    }

    void search(const std::string &query)
    {
        history.push_back(query);
        auto results = index.search(query);
        if (results.empty())
        {
            std::cout << "No results found for: " << query << std::endl;
            return;
        }
        for (int pageId : results)
        {
            std::cout << "Found: " << pages[pageId].url << std::endl;
        }
    }

    void showHistory() const
    {
        for (const std::string &q : history)
        {
            std::cout << q << std::endl;
        }
    }
};

int main()
{
    SearchEngine engine;

    engine.addPage(WebPage("https://example1.com", "Example content with data structures"));
    engine.addPage(WebPage("https://example2.com", "Another example with algorithms"));
    engine.search("data");
    engine.search("algorithms");
    engine.showHistory();

    return 0;
}