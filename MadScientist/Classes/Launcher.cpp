#include "Launcher.h"

USING_NS_CC;

Scene* Launcher::createScene()
{
    return Launcher::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Launcher.cpp\n");
}

// on "init" you need to initialize your instance
bool Launcher::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add "Launcher" splash screen
    auto background = Sprite::create("Backgrounds/4.png");
    if (background == nullptr)
    {
        problemLoading("'Backgrounds/4.png'");
    }
    else
    {
        background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        background->setScale(1.0f);
        this->addChild(background, 0);
    }

    // Thêm text vào màn hình
    auto label1 = Label::createWithTTF("Mad", "fonts/Marker Felt.ttf", 50);
    if (label1 != nullptr)
    {
        label1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 200, visibleSize.height / 2 + origin.y + 200));
        label1->setTextColor(Color4B::WHITE);
        this->addChild(label1, 1);

        // Thêm hiệu ứng đổ bóng
        label1->enableShadow(Color4B::BLACK, Size(10, -10), 0.5f);

        // Tạo hiệu ứng chuyển màu từ tím sang xanh dương
        auto tintTo1 = TintTo::create(3.0f, 128, 0, 128);  // Màu tím (RGB: 128, 0, 128)
        auto tintTo2 = TintTo::create(3.0f, 0, 0, 255);    // Màu xanh dương (RGB: 0, 0, 255)

        // Thực hiện hiệu ứng thay đổi màu sắc liên tục
        auto sequence = Sequence::create(tintTo1, tintTo2, nullptr);  // Kết hợp cả hai hiệu ứng trong một chuỗi
        auto repeat = RepeatForever::create(sequence);  // Lặp lại mãi mãi
        label1->runAction(repeat);
    }

    auto label2 = Label::createWithTTF("Scientist", "fonts/Marker Felt.ttf", 150);
    if (label2 != nullptr)
    {
        label2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 100));
        label2->setTextColor(Color4B::WHITE);
        this->addChild(label2, 1);

        // Thêm hiệu ứng đổ bóng
        label2->enableShadow(Color4B::BLACK, Size(10, -10), 0.5f);

        // Tạo hiệu ứng màu sắc: chuyển từ màu tím sang xanh
        auto tintTo1 = TintTo::create(3.0f, 128, 0, 128);  // Màu tím (RGB: 128, 0, 128)
        auto tintTo2 = TintTo::create(3.0f, 0, 255, 0);    // Màu xanh (RGB: 0, 255, 0)

        // Thực hiện hiệu ứng thay đổi màu sắc liên tục
        auto sequence = Sequence::create(tintTo1, tintTo2, nullptr);  // Kết hợp cả hai hiệu ứng trong một chuỗi
        auto repeat = RepeatForever::create(sequence);  // Lặp lại mãi mãi
        label2->runAction(repeat);
    }

    //// Tạo nhân vật
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Idle.plist");
    //Vector<SpriteFrame*> idleFrames;
    //for (int i = 0; i < 14; ++i)
    //{
    //    auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("Idle_" + std::to_string(i) + ".png");
    //    if (frame != nullptr)
    //    {
    //        idleFrames.pushBack(frame);
    //    }
    //}

    //// Tạo animation từ các frame idle
    //auto idleAnimation = Animation::createWithSpriteFrames(idleFrames, 0.2f);

    //// Tạo sprite cho nhân vật và chạy animation idle
    //auto characterSprite = Sprite::createWithSpriteFrameName("Idle_0.png");
    //characterSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 200));
    //this->addChild(characterSprite, 1);

    //// Chạy animation idle
    //auto idleAction = Animate::create(idleAnimation);
    //characterSprite->runAction(RepeatForever::create(idleAction));

    return true;
}