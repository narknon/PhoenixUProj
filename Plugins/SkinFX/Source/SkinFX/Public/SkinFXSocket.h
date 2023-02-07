#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEnvelopeColorMod.h"
#include "ESkinFXSocketOutput.h"
#include "ESkinFXSocketOutputAlphaPack.h"
#include "SkinFXBoneProperty.h"
#include "SkinFXMaterialParamProperty.h"
#include "SkinFXSocketAdvanced.h"
#include "SkinFXSocketProperty.h"
#include "SkinFXSocket.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXSocket {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialParamProperty MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXSocketProperty Socket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXBoneProperty Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXSocketOutput SocketOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXSocketOutputAlphaPack SocketOutputAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiplyColorByEnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEnvelopeColorMod EnvelopeColorMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiplyScalarByEnvelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXSocketAdvanced Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseReferencePose;
    
    SKINFX_API FSkinFXSocket();
};

