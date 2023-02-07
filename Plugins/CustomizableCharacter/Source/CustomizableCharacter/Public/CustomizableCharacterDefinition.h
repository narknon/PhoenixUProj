#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterPieceDefinition.h"
#include "EGenderEnum.h"
#include "OutfitDefinition.h"
#include "CustomizableCharacterDefinition.generated.h"

class UObject;

UCLASS(Blueprintable)
class CUSTOMIZABLECHARACTER_API UCustomizableCharacterDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> BoneScaleValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCharacterPieceDefinition> CharacterItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FOutfitDefinition> Outfits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> ExtraObjects;
    
    UCustomizableCharacterDefinition();
};

