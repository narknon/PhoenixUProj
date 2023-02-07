#pragma once
#include "CoreMinimal.h"
#include "DebugWindow.h"
#include "DebugLayeredBlend.generated.h"

class AActor;

UCLASS(Blueprintable)
class AVAANIMATION_API UDebugLayeredBlend : public UDebugWindow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DebugActor;
    
    UDebugLayeredBlend();
};

