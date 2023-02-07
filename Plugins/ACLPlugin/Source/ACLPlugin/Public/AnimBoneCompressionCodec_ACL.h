#pragma once
#include "CoreMinimal.h"
#include "AnimBoneCompressionCodec_ACLBase.h"
#include "AnimBoneCompressionCodec_ACL.generated.h"

class UAnimBoneCompressionCodec;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UAnimBoneCompressionCodec_ACL : public UAnimBoneCompressionCodec_ACLBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimBoneCompressionCodec* SafetyFallbackCodec;
    
    UAnimBoneCompressionCodec_ACL();
};

