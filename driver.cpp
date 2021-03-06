#include <QJsonArray>
#include "driver.h"

Driver::Driver() : name(""), dx(0), move(0.0), vehicle(NULL) {

}

QString Driver::getName() {
    return name;
}

void Driver::setName(const QString name) {
    this->name = name;
}

void Driver::fromJson(const QJsonObject &parent) {
    name = parent["name"].toString();
    dx = parent["DX"].toInt();
    move = parent["move"].toInt();
    QJsonArray arrskill = parent["skills"].toArray();
    for (int i = 0; i < arrskill.size(); ++i) {
        Skill newSkill;
        newSkill.fromJson(arrskill[i].toObject());
        skills.push_back(newSkill);
    }

}

QJsonObject &Driver::toJson() {
    QJsonObject *root = new QJsonObject();
    (*root)["name"] = name;
    (*root)["DX"] = dx;
    (*root)["move"] = move;

    QJsonArray skillsArray;
    for (auto skill : skills) {
        skillsArray.append(skill.toJson());
    }
    (*root)["skills"] = skillsArray;
    return *root;
}

int Driver::skillCount() {
    return skills.size();
}

Skill &Driver::getSkill(int index) {
    if (index < skills.size()) {
        return skills[index];
    } else {
        return *(new Skill());
    }
}

int Driver::getSkillLevel(QString name) {
    for (Skill sp : skills) {
        if (sp.getName() == name) {
            return sp.getLevel();
        }
    }
    return -1;
}

void Driver::setSkill(Skill &skill) {
    for (Skill &sp : skills) {
        if (sp.getName() == skill.getName()) {
            sp.setLevel(skill.getLevel());
            return;
        }
    }

    skills.push_back(skill);
}

int Driver::getDX() {
    return dx;
}

void Driver::setDX(int dx) {
    this->dx = dx;
}

double Driver::getMove() {
    if (vehicle) {
        return vehicle->getMaxSpeed();
    }
    return move;
}

void Driver::setMove(int move) {
    this->move = move;
}

void Driver::setVehicle(Vehicle *v) {
    vehicle = v;
}

Vehicle *Driver::getVehicle() {
    return vehicle;
}

int Driver::getEffectiveSkill() {
    if (NULL == vehicle) {
        return getEffectiveRunningSkill();
    }
    return getEffectiveVehicleSkill();
}

int Driver::getEffectiveRunningSkill() {
    int level = getSkillLevel("Running");
    if (-1 == level) {
        level = dx;
    }
    return level;
}

int Driver::getEffectiveVehicleSkill() {
    int level = getSkillLevel(vehicle->getSkill());
    if (-1 == level) {
        level = dx - 5;
    }
    return level;
}

int Driver::getSpeedBonusRunning(int testSpeed) {
    int bonus = 3;
    if (testSpeed < 5)
        bonus = 0;
    else if (testSpeed < 6) {
        bonus = 2;
    }
    return bonus;
}

int Driver::getSpeedBonusVehicle() {
    int bonus = -1;
    return bonus;
}

int Driver::getSpeedBonus() {
    int speed = 0;
    if (NULL == vehicle) {
        speed = move * 2;
    } else {
        speed = vehicle->getMaxSpeed();
    }

    struct speedbonus {
        int speed;
        int bonus;
    };

        speedbonus benefits[] = {
            {.speed = 200, .bonus = 10},
            {.speed = 140, .bonus = 9},
            {.speed = 100, .bonus = 8},
            {.speed = 60, .bonus = 7},
            {.speed = 40, .bonus = 6},
            {.speed = 30, .bonus = 5},
            {.speed = 20, .bonus = 4},
            {.speed = 12, .bonus = 3},
            {.speed = 10, .bonus = 2},
            {.speed = 0, .bonus = 0}
    };

    for (speedbonus b : benefits) {
        if (speed >= b.speed) {
            return b.bonus;
        }
    }

}
