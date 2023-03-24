#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MapPlayerController.generated.h"

class AUMGInputManager;

UCLASS(Blueprintable)
class AMapPlayerController : public APlayerController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AUMGInputManager* UMGInputManager;
    
public:
    AMapPlayerController(const FObjectInitializer& ObjectInitializer);
};

