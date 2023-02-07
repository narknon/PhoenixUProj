#pragma once
#include "CoreMinimal.h"
#include "DebugWindow.h"
#include "DebugAnimationTargets.generated.h"

class AActor;

UCLASS(Blueprintable)
class AVAANIMATION_API UDebugAnimationTargets : public UDebugWindow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DebugActor;
    
    UDebugAnimationTargets();
};

