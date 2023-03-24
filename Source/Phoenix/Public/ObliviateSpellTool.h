#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "ObliviateSpellTool.generated.h"

UCLASS(Blueprintable)
class AObliviateSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DazeTime;
    
    AObliviateSpellTool(const FObjectInitializer& ObjectInitializer);
};

