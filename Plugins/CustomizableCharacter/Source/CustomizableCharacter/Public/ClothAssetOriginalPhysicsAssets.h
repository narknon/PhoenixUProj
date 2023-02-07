#pragma once
#include "CoreMinimal.h"
#include "ClothAssetOriginalPhysicsAssets.generated.h"

class UClothingAssetCommon;
class UPhysicsAsset;

USTRUCT(BlueprintType)
struct FClothAssetOriginalPhysicsAssets {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UClothingAssetCommon*, UPhysicsAsset*> ClothingAssetToOriginalPhysicsAsset;
    
public:
    CUSTOMIZABLECHARACTER_API FClothAssetOriginalPhysicsAssets();
};

