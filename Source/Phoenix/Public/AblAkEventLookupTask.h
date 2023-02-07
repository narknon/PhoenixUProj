#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "GameplayTagContainer.h"
#include "AblAkEventLookupTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAkEventLookupTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer LookupTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UAblAkEventLookupTask();
};

