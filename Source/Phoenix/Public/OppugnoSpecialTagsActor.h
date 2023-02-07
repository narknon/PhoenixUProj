#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "OppugnoSpecialTagsActor.generated.h"

UINTERFACE(Blueprintable)
class UOppugnoSpecialTagsActor : public UInterface {
    GENERATED_BODY()
};

class IOppugnoSpecialTagsActor : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FGameplayTagContainer GetSpecialTags();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddSpecialTag(FGameplayTag GameplayTag);
    
};

