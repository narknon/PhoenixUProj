#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "ConfundoSpellTool.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable)
class AConfundoSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ConfundoFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DazeTime;
    
    AConfundoSpellTool();
};

