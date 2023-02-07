#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OdcDebugDrawActor.generated.h"

class UDebugPanelComponent;
class ULineBatchComponent;
class UOdcCanvasTextComponent;

UCLASS(Blueprintable, NotPlaceable)
class AOdcDebugDrawActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOdcCanvasTextComponent* CanvasTextComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULineBatchComponent* LineBatchComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDebugPanelComponent* DebugPanel;
    
    AOdcDebugDrawActor();
};

