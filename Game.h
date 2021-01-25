#pragma once
#include <iostream>
#include <string>

using namespace std;

class Achievement {
public:
	Achievement() : title_("none"), description_("none"), score_(0) {}
	Achievement(string t, string d, int s) : title_(t), description_(d), score_(s) {}
	void init(string t, string d, int s) {
		title_ = t;
		description_ = d;
		score_ = s;
	}
	void display(string indent) {
		cout << indent << "Title: " << title_ << endl;
		cout << indent << "  Description: " <<  description_ << endl; 
		cout << indent << "  Score: " << score_ << endl;
	}

private:
	string title_;
	string description_;
	int score_;
};

class Game {
public:
	Game() : name_("none"), publisher_("none"), developer_("none"), achievements_(nullptr), achievementSize_(0) {
		achievements_ = new Achievement[100];
	}
	Game(string n, string p, string d) : name_(n), publisher_(p), developer_(d), achievements_(nullptr), achievementSize_(0) {
		achievements_ = new Achievement[100];
	}
	~Game() {
		delete[] achievements_;
	}
	void init(string n, string p, string d) {
		name_ = n;
		publisher_ = p;
		developer_ = d;
	}
	void display(string indent) {
		cout << indent << name_ << " -- " << publisher_ << " -- " << developer_ << " -- " << achievementSize_ << " achievements" << endl;
		for (int i = 0; i < achievementSize_; ++i) {
			string nextIndent = indent + "  ";
			achievements_[i].display(nextIndent);
		}
	}
	void addAchievement(string t, string d, int s) {
		achievements_[achievementSize_].init(t, d, s);
		++achievementSize_;
	}
	string getName() {
		return name_;
	}

public:
	string name_;
	string publisher_;
	string developer_;
	Achievement* achievements_;
	int achievementSize_;
};

class Platform {
public:
	Platform() : name_("none"), manufacturer_("none"), games_(nullptr), gameSize_(0) {
		games_ = new Game[100];
	}
	Platform(string n, string m) : name_(n), manufacturer_(m), games_(nullptr), gameSize_(0) {
		games_ = new Game[100];
	}
	~Platform() {
		delete[] games_;
	}
	void init(string n, string m) { 
		name_ = n; manufacturer_ = m; 
	}
	void display() {
		cout << name_ << " -- " << manufacturer_ << " -- " << gameSize_ << " games" << endl;
		for (int i = 0; i < gameSize_; ++i) {
			string indent = "  ";
			games_[i].display(indent);
		}
	}
	void addGame(string n, string p, string d) {
		games_[gameSize_].init(n, p, d);
		++gameSize_;
	}
	// find game by name
	Game* findGame(string n) {
		for (int i = 0; i < gameSize_; ++i) {
			if (games_[i].getName() == n)
				return &games_[i];
		}
		return nullptr;
	}
	// display all games' names
	void displayGameNames() {
		for (int i = 0; i < gameSize_; ++i) {
			cout << i + 1 << ". " << games_[i].getName() << endl;
		}
		cout << endl;
	}
	// add achievement to game foud by index
	void addAchievement(int idx, string t, string d, int s) {
		games_[idx].addAchievement(t, d, s);
	}
	string getName() { return name_; }
	int getGameSize() { return gameSize_; }

private:
	string name_;
	string manufacturer_;
	Game* games_;
	int gameSize_;
};