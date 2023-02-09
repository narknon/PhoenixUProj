#pragma once
#include "CoreMinimal.h"
#include "ClothingAssetName.generated.h"

USTRUCT(BlueprintType)
struct FClothingAssetName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    CUSTOMIZABLECHARACTER_API FClothingAssetName();
};

FORCEINLINE uint32 GetTypeHash(const FClothingAssetName) { return 0; }