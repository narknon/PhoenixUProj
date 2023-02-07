#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OutfitDefinition.h"
#include "OutfitDefinitionWrapper.generated.h"

UCLASS(Blueprintable)
class UOutfitDefinitionWrapper : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOutfitDefinition OutfitDefinition;
    
    UOutfitDefinitionWrapper();
};

