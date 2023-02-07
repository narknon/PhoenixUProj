#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
#include "AblAbilityTask.h"
#include "AblSetShaderParameterTask.generated.h"

class UAblSetParameterValue;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblSetShaderParameterTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_ParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblSetParameterValue* m_value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RestoreValueOnEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_BlendOut;
    
public:
    UAblSetShaderParameterTask();
};

