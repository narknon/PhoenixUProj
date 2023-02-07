#pragma once
#include "CoreMinimal.h"
#include "ToolRecord.h"
#include "SpellToolRecord.generated.h"

class ASpellTool;

UCLASS(Blueprintable)
class USpellToolRecord : public UToolRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASpellTool> SpellTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AudioSwitchName;
    
    USpellToolRecord();
    UFUNCTION(BlueprintCallable)
    void LoadComplete();
    
};

