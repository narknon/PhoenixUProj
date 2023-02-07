#pragma once
#include "CoreMinimal.h"
#include "AblSetParameterValue.h"
#include "AblSetTextureParameterValue.generated.h"

class UTexture;

UCLASS(Blueprintable, EditInlineNew)
class UAblSetTextureParameterValue : public UAblSetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* m_Texture;
    
public:
    UAblSetTextureParameterValue();
};

