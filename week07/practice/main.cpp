#include <cassert>
#include "InstagramPost.h"
#include "InstagramProfile.h"

void createArrayOfPosts(const char *fileName)
{
    std::ofstream os(fileName);

    InstagramPost ip("This ASCII art depicts a beautiful sunset with a sun setting behind mountains, and the sky turning orange and red. The reflection of the sunset can be seen in the water below.", "sunset.photo");
    ip.like();
    ip.like();

    InstagramPost ip1("This ASCII art shows a basic representation of a human face, with eyes, nose, and mouth. The face is looking straight ahead, and the mouth is curved into a slight smile. I hope you like it!", "selfie.photo");
    ip1.like();

    os.write((char *)&ip, sizeof(ip));
    os.write((char *)&ip1, sizeof(ip1));

    os.close();
}

void runTests()
{
    const char profileName[] = "profile.dat";
    createArrayOfPosts(profileName);

    InstagramProfile profile("AnimalLover123", profileName, 3);
    std::cout << profile[0];
    std::cout << profile[1];
    assert(profile.isEmpty(2));

    try
    {
        std::cout << profile[2];
        assert(false);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(true);
    }

    InstagramPost cow("Cow.", "cow.photo");
    profile += cow;
    std::cout << profile[2];

    InstagramPost dog("Dog.", "dog.photo");
    profile += dog;
    try
    {
        std::cout << profile[3];
        assert(false);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        assert(true);
    }
    std::cout << profile[2];

    InstagramProfile profile1("Ivan", profileName, 1);
    std::cout << profile1[0];

    std::cout << "All tests ran successfully.\n";
}

int main()
{
    runTests();
}