#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "EStreamingPlaceholderPriority.h"
#include "ETransfigurationInitialColor.h"
#include "StreamingPlaceholderBase.h"
#include "TransfigurationPlaceholder.generated.h"

class AActor;

UCLASS(Blueprintable)
class PHOENIX_API ATransfigurationPlaceholder : public AStreamingPlaceholderBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ObjectCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ObjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ExpansionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ExpandedObjectCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETransfigurationInitialColor InitialColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IdentifyingName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_StreamingPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStreamingPlaceholderPriority StreamingPriority;
    
private:
    UPROPERTY(EditAnywhere, TextExportTransient, meta=(AllowPrivateAccess=true))
    uint32 UID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SignedUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* SpawnedActor;
    
public:
    ATransfigurationPlaceholder();
};

