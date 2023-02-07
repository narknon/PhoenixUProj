#pragma once
#include "CoreMinimal.h"
#include "SetParameterValue.h"
#include "SetTextureParameterValue.generated.h"

class UTexture;

UCLASS(Blueprintable, EditInlineNew)
class USetTextureParameterValue : public USetParameterValue {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* m_Texture;
    
public:
    USetTextureParameterValue();
};

