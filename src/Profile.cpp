//
// Created by nycuro on 10/30/21.
//

#include <fstream>
#include "../includes/Utils.h"
#include "../includes/User.h"
#include <string>
#include <algorithm>

class Utils;

class User;

class UserFactory;

// Implementarea constructorului de initializare
Profile::Profile(const long &profileId, const std::vector<std::shared_ptr<Post>> &posts,
                 const std::vector<std::shared_ptr<Group>> &groups, const std::vector<std::shared_ptr<User>> &followers,
                 const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces) {
    std::cout << "[DEBUG] Apelare constructor Profile.h" << std::endl;
    this->profileId = profileId;
    this->posts = posts;
    this->groups = groups;
    this->followers = followers;
    this->studies = studies;
    this->livingPlaces = livingPlaces;
}

// Implementarea destructorului
Profile::~Profile() {
    std::cout << "[DEBUG] Apelare destructor Profile.h" << std::endl;
}

// Implementarea constructorului de copiere
Profile::Profile(const Profile &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Profile.h" << std::endl;
    this->profileId = copie.profileId;
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
}

// Implementarea operatorului =
Profile &Profile::operator=(const Profile &copie) {
    std::cout << "[DEBUG] Apelare operator = Profile.h" << std::endl;
    this->profileId = copie.profileId;
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    std::cout << "[DEBUG] Apelare operator << Profile.h" << std::endl;
    os << std::endl << profile.profileId;
    for (const auto &post : profile.posts) {
        os << std::endl << post;
    }
    for (const auto &group : profile.groups) {
        os << std::endl << group;
    }
    for (const auto &follower : profile.followers) {
        os << std::endl << follower;
    }
    for (const auto &study : profile.studies) {
        os << std::endl << study;
    }
    for (const auto &livingPlace : profile.livingPlaces) {
        os << std::endl << livingPlace;
    }
    return os;
}

// Getter pentru campul "profileId"
long& Profile::getId() {
    return this->profileId;
}

// Setter pentru campul "profileId"
void Profile::setId(const long &id) {
    this->profileId = id;
}

// Getter pentru campul "posts"
std::vector<std::shared_ptr<Post>> Profile::getPosts() {
    return this->posts;
}

// Setter pentru campul "posts_
void Profile::setPosts(std::vector<std::shared_ptr<Post>> &posts_) {
    this->posts = posts_;
}

// Getter pentru campul "groups"
std::vector<std::shared_ptr<Group>> Profile::getGroups() {
    return this->groups;
}

// Setter pentru campul "groups_"
void Profile::setGroups(const std::vector<std::shared_ptr<Group>> &groups_) {
    this->groups = groups_;
}

// Getter pentru campul "followers"
std::vector<std::shared_ptr<User>> &Profile::getFollowers() {
    return this->followers;
}

// Setter pentru campul "followers_"
void Profile::setFollowers(const std::vector<std::shared_ptr<User>> &followers_) {
    this->followers = followers_;
}

// Getter pentru campul "studies"
std::vector<std::string> &Profile::getStudies() {
    return this->studies;
}

// Setter pentru campul "studies_"
void Profile::setStudies(const std::vector<std::string> &studies_) {
    this->studies = studies_;
}

// Getter pentru campul "livingPlaces"
std::vector<std::string> &Profile::getLivingPlaces() {
    return this->livingPlaces;
}

// Setter pentru campul "livingPlaces_"
void Profile::setLivingPlaces(const std::vector<std::string> &livingPlaces_) {
    this->livingPlaces = livingPlaces_;
}

void Profile::manageExistenceProfileData() {
    std::ifstream oldFile;
    std::ofstream newFile;
    std::string data;

    oldFile.open("profiles.txt");

    bool exist = false;
    while (std::getline(oldFile, data)) {
        std::vector<std::string> fields = Utils::splitString(data, '|');
        if (fields.at(0) == std::to_string(this->getId())) {
            exist = true;
            break;
        }
    }


    data = "";
    if (exist) {
        newFile.open("profilesNew.txt", std::ios::out | std::ios::app);
        while (std::getline(oldFile, data)) {
            std::vector<std::string> fields = Utils::splitString(data, '|');
            if (fields.at(0) != std::to_string(this->getId())) {
                newFile << data << std::endl;
            }
        }
    }

    remove("profiles.txt");
    rename("profilesNew.txt", "profiles.txt");
}

void Profile::showInformationsAboutUser() {
    User::showInformationsAboutUser();
    std::cout << "Profile informations: " << std::endl;
    std::for_each(this->getFollowers().begin(), this->getFollowers().end(), [](const std::shared_ptr<User> &user) {
        std::cout << *user;
    });
    std::for_each(this->getGroups().begin(), this->getGroups().end(), [](const std::shared_ptr<Group> &group) {
        std::cout << *group;
    });
    std::for_each(this->getLivingPlaces().begin(), this->getLivingPlaces().end(), [](const std::string &livingPlace) {
        std::cout << livingPlace;
    });
    std::for_each(this->getPosts().begin(), this->getPosts().end(), [](const std::shared_ptr<Post> &post) {
        std::cout << post;
    });
    std::for_each(this->getStudies().begin(), this->getStudies().end(), [](const std::string &study) {
        std::cout << study;
    });
}
