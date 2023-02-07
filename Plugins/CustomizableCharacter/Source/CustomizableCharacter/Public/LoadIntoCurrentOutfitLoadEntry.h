#pragma once
#include "CoreMinimal.h"
#include "LoadEntry.h"
#include "OutfitDefinition.h"
#include "LoadIntoCurrentOutfitLoadEntry.generated.h"

UCLASS(Blueprintable)
class ULoadIntoCurrentOutfitLoadEntry : public ULoadEntry {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOutfitDefinition OutfitToLoad;
    
public:
    ULoadIntoCurrentOutfitLoadEntry();
};

