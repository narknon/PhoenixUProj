#pragma once
#include "CoreMinimal.h"
#include "Outfit.generated.h"

class UAddOnMeshProperties;

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FOutfit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UAddOnMeshProperties*> OutfitItems;
    
    FOutfit();
};

