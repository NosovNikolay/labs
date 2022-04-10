#include "Backpack.hpp"
enum ClothType
{
    Synthetic,
    Tarpaulin,
    Wool,
    Cotton
};
class ClothBackpack final : public Backpack
{
private:
    bool waterproof;
    ClothType cloth;

public:
    ClothBackpack();

    ClothBackpack(string color_,
                  string appointment_,
                  bool laptop_comparament_,
                  unsigned volume_,
                  bool waterproof_,
                  ClothType cloth_,
                  const struct Brand &brand_);

    ClothBackpack(const ClothBackpack &backpack);

    string ToString() const override;

    bool FillFromString(string str) override;

    Backpack *Copy() const override;

    ~ClothBackpack();
};
