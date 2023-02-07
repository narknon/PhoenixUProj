#pragma once
#include "CoreMinimal.h"
#include "TimeRigGroup.h"
#include "ESanctuaryIdentity.h"
#include "SceneGroup_SanctuaryIdentity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USceneGroup_SanctuaryIdentity : public UTimeRigGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESanctuaryIdentity Identity;
    
    USceneGroup_SanctuaryIdentity();
    UFUNCTION(BlueprintCallable)
    void OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity);
    
};

