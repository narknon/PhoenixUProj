#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "FiniteSpellTool.generated.h"

UCLASS(Blueprintable)
class AFiniteSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FiniteLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveSpellsFromOtherCasters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveBuffs;
    
public:
    AFiniteSpellTool();
};

