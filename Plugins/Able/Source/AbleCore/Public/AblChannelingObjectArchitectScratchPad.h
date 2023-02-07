#pragma once
#include "CoreMinimal.h"
#include "TagsChangedEvent.h"
#include "GameplayTagContainer.h"
#include "AblAbilityChannelingScratchPad.h"
#include "AblChannelingObjectArchitectScratchPad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblChannelingObjectArchitectScratchPad : public UAblAbilityChannelingScratchPad {
    GENERATED_BODY()
public:
    UAblChannelingObjectArchitectScratchPad();
    UFUNCTION(BlueprintCallable)
    void TagsChanged(AActor* Actor, FGameplayTag GameplayTag, TEnumAsByte<TagsChangedEvent> NewTagsChanged);
    
};

