#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapDebuggerWindow.generated.h"

class AActor;

UCLASS(Blueprintable)
class UMapDebuggerWindow : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> audioCueActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* enterLeaveActor;
    
    UMapDebuggerWindow();
};

