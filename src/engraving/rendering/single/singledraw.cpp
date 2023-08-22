/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2023 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "singledraw.h"

#include "draw/painter.h"
#include "draw/svgrenderer.h"

#include "types/typesconv.h"
#include "style/style.h"
#include "style/defaultstyle.h"

#include "libmscore/accidental.h"
#include "libmscore/actionicon.h"
#include "libmscore/ambitus.h"
#include "libmscore/arpeggio.h"
#include "libmscore/articulation.h"

#include "libmscore/bagpembell.h"
#include "libmscore/barline.h"
#include "libmscore/beam.h"
#include "libmscore/bend.h"
#include "libmscore/bracket.h"
#include "libmscore/breath.h"

#include "libmscore/chordline.h"
#include "libmscore/clef.h"
#include "libmscore/capo.h"

#include "libmscore/deadslapped.h"
#include "libmscore/dynamic.h"

#include "libmscore/expression.h"

#include "libmscore/fermata.h"
#include "libmscore/figuredbass.h"
#include "libmscore/fingering.h"
#include "libmscore/fret.h"

#include "libmscore/glissando.h"
#include "libmscore/gradualtempochange.h"

#include "libmscore/hairpin.h"
#include "libmscore/harppedaldiagram.h"
#include "libmscore/harmonicmark.h"
#include "libmscore/harmony.h"
#include "libmscore/hook.h"

#include "libmscore/image.h"
#include "libmscore/instrchange.h"
#include "libmscore/instrumentname.h"

#include "libmscore/jump.h"

#include "libmscore/keysig.h"

#include "libmscore/layoutbreak.h"
#include "libmscore/ledgerline.h"
#include "libmscore/letring.h"

#include "libmscore/marker.h"
#include "libmscore/measurenumber.h"
#include "libmscore/measurerepeat.h"

#include "libmscore/note.h"

#include "libmscore/ornament.h"
#include "libmscore/ottava.h"

#include "libmscore/palmmute.h"
#include "libmscore/part.h"
#include "libmscore/pedal.h"
#include "libmscore/pickscrape.h"
#include "libmscore/playtechannotation.h"

#include "libmscore/rasgueado.h"
#include "libmscore/rehearsalmark.h"
#include "libmscore/rest.h"

#include "libmscore/score.h"
#include "libmscore/shadownote.h"
#include "libmscore/slur.h"
#include "libmscore/spacer.h"
#include "libmscore/staffstate.h"
#include "libmscore/stafftext.h"
#include "libmscore/stafftypechange.h"
#include "libmscore/stem.h"
#include "libmscore/stemslash.h"
#include "libmscore/sticking.h"
#include "libmscore/stretchedbend.h"
#include "libmscore/symbol.h"
#include "libmscore/systemdivider.h"
#include "libmscore/systemtext.h"

#include "libmscore/tempotext.h"
#include "libmscore/text.h"
#include "libmscore/textbase.h"
#include "libmscore/textline.h"
#include "libmscore/textlinebase.h"
#include "libmscore/tie.h"
#include "libmscore/timesig.h"
#include "libmscore/tremolo.h"
#include "libmscore/tremolobar.h"
#include "libmscore/trill.h"
#include "libmscore/tripletfeel.h"
#include "libmscore/tuplet.h"

#include "libmscore/vibrato.h"
#include "libmscore/volta.h"

#include "libmscore/whammybar.h"

#include "libmscore/mscoreview.h"

#include "infrastructure/rtti.h"

using namespace mu::engraving::rendering::single;
using namespace mu::engraving;
using namespace mu::engraving::rtti;
using namespace mu::draw;

void SingleDraw::drawItem(const EngravingItem* item, draw::Painter* painter)
{
    switch (item->type()) {
    case ElementType::ACCIDENTAL:   draw(item_cast<const Accidental*>(item), painter);
        break;
    case ElementType::ACTION_ICON:  draw(item_cast<const ActionIcon*>(item), painter);
        break;
    case ElementType::AMBITUS:      draw(item_cast<const Ambitus*>(item), painter);
        break;
    case ElementType::ARPEGGIO:     draw(item_cast<const Arpeggio*>(item), painter);
        break;
    case ElementType::ARTICULATION: draw(item_cast<const Articulation*>(item), painter);
        break;

    case ElementType::BAGPIPE_EMBELLISHMENT: draw(item_cast<const BagpipeEmbellishment*>(item), painter);
        break;
    case ElementType::BAR_LINE:     draw(item_cast<const BarLine*>(item), painter);
        break;
    case ElementType::BEAM:         draw(item_cast<const Beam*>(item), painter);
        break;
    case ElementType::BEND:         draw(item_cast<const Bend*>(item), painter);
        break;
    case ElementType::BRACKET:      draw(item_cast<const Bracket*>(item), painter);
        break;
    case ElementType::BREATH:       draw(item_cast<const Breath*>(item), painter);
        break;

    case ElementType::CHORDLINE:    draw(item_cast<const ChordLine*>(item), painter);
        break;
    case ElementType::CLEF:         draw(item_cast<const Clef*>(item), painter);
        break;
    case ElementType::CAPO:         draw(item_cast<const Capo*>(item), painter);
        break;

    case ElementType::DEAD_SLAPPED: draw(item_cast<const DeadSlapped*>(item), painter);
        break;
    case ElementType::DYNAMIC:      draw(item_cast<const Dynamic*>(item), painter);
        break;

    case ElementType::EXPRESSION:   draw(item_cast<const Expression*>(item), painter);
        break;

    case ElementType::FERMATA:      draw(item_cast<const Fermata*>(item), painter);
        break;
    case ElementType::FIGURED_BASS: draw(item_cast<const FiguredBass*>(item), painter);
        break;
    case ElementType::FINGERING:    draw(item_cast<const Fingering*>(item), painter);
        break;
    case ElementType::FRET_DIAGRAM: draw(item_cast<const FretDiagram*>(item), painter);
        break;
    case ElementType::FSYMBOL:      draw(item_cast<const FSymbol*>(item), painter);
        break;

    case ElementType::GLISSANDO_SEGMENT: draw(item_cast<const GlissandoSegment*>(item), painter);
        break;
    case ElementType::GRADUAL_TEMPO_CHANGE_SEGMENT: draw(item_cast<const GradualTempoChangeSegment*>(item), painter);
        break;

    case ElementType::HAIRPIN_SEGMENT: draw(item_cast<const HairpinSegment*>(item), painter);
        break;
    case ElementType::HARP_DIAGRAM: draw(item_cast<const HarpPedalDiagram*>(item), painter);
        break;
    case ElementType::HARMONIC_MARK_SEGMENT: draw(item_cast<const HarmonicMarkSegment*>(item), painter);
        break;
    case ElementType::HARMONY:      draw(item_cast<const Harmony*>(item), painter);
        break;
    case ElementType::HOOK:         draw(item_cast<const Hook*>(item), painter);
        break;

    case ElementType::IMAGE:        draw(item_cast<const Image*>(item), painter);
        break;
    case ElementType::INSTRUMENT_CHANGE: draw(item_cast<const InstrumentChange*>(item), painter);
        break;
    case ElementType::INSTRUMENT_NAME: draw(item_cast<const InstrumentName*>(item), painter);
        break;

    case ElementType::JUMP:         draw(item_cast<const Jump*>(item), painter);
        break;

    case ElementType::KEYSIG:       draw(item_cast<const KeySig*>(item), painter);
        break;

    case ElementType::LAYOUT_BREAK: draw(item_cast<const LayoutBreak*>(item), painter);
        break;
    case ElementType::LEDGER_LINE:  draw(item_cast<const LedgerLine*>(item), painter);
        break;
    case ElementType::LET_RING_SEGMENT:     draw(item_cast<const LetRingSegment*>(item), painter);
        break;

    case ElementType::MARKER:               draw(item_cast<const Marker*>(item), painter);
        break;
    case ElementType::MEASURE_NUMBER:       draw(item_cast<const MeasureNumber*>(item), painter);
        break;
    case ElementType::MEASURE_REPEAT:       draw(item_cast<const MeasureRepeat*>(item), painter);
        break;

    case ElementType::NOTE:                 draw(item_cast<const Note*>(item), painter);
        break;
    case ElementType::NOTEHEAD:             draw(item_cast<const NoteHead*>(item), painter);
        break;

    case ElementType::ORNAMENT:             draw(item_cast<const Ornament*>(item), painter);
        break;
    case ElementType::OTTAVA_SEGMENT:       draw(item_cast<const OttavaSegment*>(item), painter);
        break;

    case ElementType::PALM_MUTE_SEGMENT:    draw(item_cast<const PalmMuteSegment*>(item), painter);
        break;
    case ElementType::PEDAL_SEGMENT:        draw(item_cast<const PedalSegment*>(item), painter);
        break;
    case ElementType::PICK_SCRAPE_SEGMENT:  draw(item_cast<const PickScrapeSegment*>(item), painter);
        break;
    case ElementType::PLAYTECH_ANNOTATION:  draw(item_cast<const PlayTechAnnotation*>(item), painter);
        break;

    case ElementType::RASGUEADO_SEGMENT:    draw(item_cast<const RasgueadoSegment*>(item), painter);
        break;
    case ElementType::REHEARSAL_MARK:       draw(item_cast<const RehearsalMark*>(item), painter);
        break;
    case ElementType::REST:                 draw(item_cast<const Rest*>(item), painter);
        break;

    case ElementType::SHADOW_NOTE:          draw(item_cast<const ShadowNote*>(item), painter);
        break;
    case ElementType::SLUR_SEGMENT:         draw(item_cast<const SlurSegment*>(item), painter);
        break;
    case ElementType::SPACER:               draw(item_cast<const Spacer*>(item), painter);
        break;
    case ElementType::STAFF_STATE:          draw(item_cast<const StaffState*>(item), painter);
        break;
    case ElementType::STAFF_TEXT:           draw(item_cast<const StaffText*>(item), painter);
        break;
    case ElementType::STAFFTYPE_CHANGE:     draw(item_cast<const StaffTypeChange*>(item), painter);
        break;
    case ElementType::STEM:                 draw(item_cast<const Stem*>(item), painter);
        break;
    case ElementType::STEM_SLASH:           draw(item_cast<const StemSlash*>(item), painter);
        break;
    case ElementType::STICKING:             draw(item_cast<const Sticking*>(item), painter);
        break;
    case ElementType::STRETCHED_BEND:       draw(item_cast<const StretchedBend*>(item), painter);
        break;
    case ElementType::SYMBOL:               draw(item_cast<const Symbol*>(item), painter);
        break;
    case ElementType::SYSTEM_DIVIDER:       draw(item_cast<const SystemDivider*>(item), painter);
        break;
    case ElementType::SYSTEM_TEXT:          draw(item_cast<const SystemText*>(item), painter);
        break;

    case ElementType::TEMPO_TEXT:           draw(item_cast<const TempoText*>(item), painter);
        break;
    case ElementType::TEXT:                 draw(item_cast<const Text*>(item), painter);
        break;
    case ElementType::TEXTLINE_SEGMENT:     draw(item_cast<const TextLineSegment*>(item), painter);
        break;
    case ElementType::TIE_SEGMENT:          draw(item_cast<const TieSegment*>(item), painter);
        break;
    case ElementType::TIMESIG:              draw(item_cast<const TimeSig*>(item), painter);
        break;
    case ElementType::TREMOLO:              draw(item_cast<const Tremolo*>(item), painter);
        break;
    case ElementType::TREMOLOBAR:           draw(item_cast<const TremoloBar*>(item), painter);
        break;
    case ElementType::TRILL_SEGMENT:        draw(item_cast<const TrillSegment*>(item), painter);
        break;
    case ElementType::TRIPLET_FEEL:         draw(item_cast<const TripletFeel*>(item), painter);
        break;
    case ElementType::TUPLET:               draw(item_cast<const Tuplet*>(item), painter);
        break;

    case ElementType::VIBRATO_SEGMENT:      draw(item_cast<const VibratoSegment*>(item), painter);
        break;
    case ElementType::VOLTA_SEGMENT:        draw(item_cast<const VoltaSegment*>(item), painter);
        break;

    case ElementType::WHAMMY_BAR_SEGMENT:   draw(item_cast<const WhammyBarSegment*>(item), painter);
        break;
    default:
        NOT_IMPLEMENTED << item->typeName();
        UNREACHABLE;
    }
}

void SingleDraw::draw(const Accidental* item, draw::Painter* painter)
{
    IF_ASSERT_FAILED(item->layoutData()) {
        return;
    }

    painter->setPen(item->curColor());
    for (const Accidental::LayoutData::Sym& e : item->layoutData()->syms) {
        item->drawSymbol(e.sym, painter, PointF(e.x, e.y));
    }
}

void SingleDraw::draw(const ActionIcon* item, draw::Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setFont(item->iconFont());
    painter->drawText(item->bbox(), draw::AlignCenter, Char(item->icon()));
}

void SingleDraw::draw(const Ambitus* item, draw::Painter* painter)
{
    TRACE_DRAW_ITEM;

    const Ambitus::LayoutData* layoutData = item->layoutData();
    IF_ASSERT_FAILED(layoutData) {
        return;
    }

    double spatium = item->spatium();
    double lw = item->lineWidth().val() * spatium;
    painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));

    item->drawSymbol(item->noteHead(), painter, layoutData->topPos);
    item->drawSymbol(item->noteHead(), painter, layoutData->bottomPos);
    if (item->hasLine()) {
        painter->drawLine(layoutData->line);
    }
}

void SingleDraw::draw(const Arpeggio* item, draw::Painter* painter)
{
    TRACE_DRAW_ITEM;

    const Arpeggio::LayoutData* layoutData = item->layoutData();
    IF_ASSERT_FAILED(layoutData) {
        return;
    }

    const double y1 = layoutData->bbox.top();
    const double y2 = layoutData->bbox.bottom();
    const double lineWidth = item->style().styleMM(Sid::ArpeggioLineWidth);

    painter->setPen(Pen(item->curColor(), lineWidth, PenStyle::SolidLine, PenCapStyle::FlatCap));
    painter->save();

    switch (item->arpeggioType()) {
    case ArpeggioType::NORMAL:
    case ArpeggioType::UP:
    {
        const RectF& r = layoutData->symsBBox;
        painter->rotate(-90.0);
        item->drawSymbols(layoutData->symbols, painter, PointF(-r.right() - y1, -r.bottom() + r.height()));
    } break;

    case ArpeggioType::DOWN:
    {
        const RectF& r = layoutData->symsBBox;
        painter->rotate(90.0);
        item->drawSymbols(layoutData->symbols, painter, PointF(-r.left() + y1, -r.top() - r.height()));
    } break;

    case ArpeggioType::UP_STRAIGHT:
    {
        const RectF& r = layoutData->symsBBox;
        double x1 = item->spatium() * 0.5;
        item->drawSymbol(SymId::arrowheadBlackUp, painter, PointF(x1 - r.width() * 0.5, y1 - r.top()));
        double ny1 = y1 - r.top() * 0.5;
        painter->drawLine(LineF(x1, ny1, x1, y2));
    } break;

    case ArpeggioType::DOWN_STRAIGHT:
    {
        const RectF& r = layoutData->symsBBox;
        double x1 = item->spatium() * 0.5;
        item->drawSymbol(SymId::arrowheadBlackDown, painter, PointF(x1 - r.width() * 0.5, y2 - r.bottom()));
        double ny2 = y2 + r.top() * 0.5;
        painter->drawLine(LineF(x1, y1, x1, ny2));
    } break;

    case ArpeggioType::BRACKET:
    {
        double w = item->style().styleS(Sid::ArpeggioHookLen).val() * item->spatium();
        painter->drawLine(LineF(0.0, y1, w, y1));
        painter->drawLine(LineF(0.0, y2, w, y2));
        painter->drawLine(LineF(0.0, y1 - lineWidth / 2, 0.0, y2 + lineWidth / 2));
    } break;
    }
    painter->restore();
}

void SingleDraw::draw(const Articulation* item, draw::Painter* painter)
{
    TRACE_DRAW_ITEM;

    painter->setPen(item->curColor());

    if (item->textType() == ArticulationTextType::NO_TEXT) {
        item->drawSymbol(item->symId(), painter, PointF(-0.5 * item->width(), 0.0));
    } else {
        mu::draw::Font scaledFont(item->font());
        scaledFont.setPointSizeF(scaledFont.pointSizeF() * item->magS() * MScore::pixelRatio);
        painter->setFont(scaledFont);
        painter->drawText(item->bbox(), TextDontClip | AlignLeft | AlignTop, TConv::text(item->textType()));
    }
}

void SingleDraw::draw(const Note* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (item->hidden()) {
        return;
    }

    auto config = item->engravingConfiguration();

    bool negativeFret = item->negativeFretUsed() && item->staff()->isTabStaff(item->tick());

    Color c(negativeFret ? config->criticalColor() : item->curColor());
    painter->setPen(c);
    bool tablature = item->staff() && item->staff()->isTabStaff(item->chord()->tick());

    // tablature
    if (tablature) {
        if (item->displayFret() == Note::DisplayFretOption::Hide) {
            return;
        }
        const Staff* st = item->staff();
        const StaffType* tab = st->staffTypeForElement(item);
        if (item->tieBack() && !tab->showBackTied()) {
            if (item->chord()->measure()->system() == item->tieBack()->startNote()->chord()->measure()->system() && item->el().empty()) {
                // fret should be hidden, so return without drawing it
                return;
            }
        }
        // draw background, if required (to hide a segment of string line or to show a fretting conflict)
        if (!tab->linesThrough() || item->fretConflict()) {
            double d  = item->spatium() * .1;
            RectF bb
                = RectF(item->bbox().x() - d, tab->fretMaskY() * item->magS(), item->bbox().width() + 2 * d,
                        tab->fretMaskH() * item->magS());
            // we do not know which viewer did this draw() call
            // so update all:
            if (!item->score()->getViewer().empty()) {
                for (MuseScoreView* view : item->score()->getViewer()) {
                    view->drawBackground(painter, bb);
                }
            } else {
                painter->fillRect(bb, config->noteBackgroundColor());
            }

            if (item->fretConflict() && !item->score()->printing() && item->score()->showUnprintable()) {                //on fret conflict, draw on red background
                painter->save();
                painter->setPen(config->criticalColor());
                painter->setBrush(config->criticalColor());
                painter->drawRect(bb);
                painter->restore();
            }
        }
        mu::draw::Font f(tab->fretFont());
        f.setPointSizeF(f.pointSizeF() * item->magS() * MScore::pixelRatio);
        painter->setFont(f);
        painter->setPen(c);
        double startPosX = item->bbox().x();
        if (item->ghost() && config->tablatureParenthesesZIndexWorkaround()) {
            startPosX += item->symWidth(SymId::noteheadParenthesisLeft);
        }

        painter->drawText(PointF(startPosX, tab->fretFontYOffset() * item->magS()), item->fretString());
    }
    // NOT tablature
    else {
        // skip drawing, if second note of a cross-measure value
        if (item->chord() && item->chord()->crossMeasure() == CrossMeasure::SECOND) {
            return;
        }
        // warn if pitch extends usable range of instrument
        // by coloring the notehead
        if (item->chord() && item->chord()->segment() && item->staff()
            && !item->score()->printing() && MScore::warnPitchRange && !item->staff()->isDrumStaff(item->chord()->tick())) {
            const Instrument* in = item->part()->instrument(item->chord()->tick());
            int i = item->ppitch();
            if (i < in->minPitchP() || i > in->maxPitchP()) {
                painter->setPen(
                    item->selected() ? config->criticalSelectedColor() : config->criticalColor());
            } else if (i < in->minPitchA() || i > in->maxPitchA()) {
                painter->setPen(item->selected() ? config->warningSelectedColor() : config->warningColor());
            }
        }
        // Warn if notes are unplayable based on previous harp diagram setting
        if (item->chord() && item->chord()->segment() && item->staff() && !item->score()->printing()
            && !item->staff()->isDrumStaff(item->chord()->tick())) {
            HarpPedalDiagram* prevDiagram = item->part()->currentHarpDiagram(item->chord()->segment()->tick());
            if (prevDiagram && !prevDiagram->isPitchPlayable(item->ppitch())) {
                painter->setPen(item->selected() ? config->criticalSelectedColor() : config->criticalColor());
            }
        }
        // draw blank notehead to avoid staff and ledger lines
        if (item->cachedSymNull() != SymId::noSym) {
            painter->save();
            painter->setPen(config->noteBackgroundColor());
            item->drawSymbol(item->cachedSymNull(), painter);
            painter->restore();
        }
        item->drawSymbol(item->cachedNoteheadSym(), painter);
    }
}

void SingleDraw::draw(const NoteHead* item, Painter* painter)
{
    draw(static_cast<const Symbol*>(item), painter);
}

void SingleDraw::draw(const Ornament* item, draw::Painter* painter)
{
    draw(static_cast<const Articulation*>(item), painter);
}

void SingleDraw::draw(const BagpipeEmbellishment* item, draw::Painter* painter)
{
    TRACE_DRAW_ITEM;

    const BagpipeEmbellishment::LayoutData* data = item->layoutData();
    IF_ASSERT_FAILED(data) {
        return;
    }
    const BagpipeEmbellishment::LayoutData::BeamData& dataBeam = data->beamData;

    Pen pen(item->curColor(), data->stemLineW, PenStyle::SolidLine, PenCapStyle::FlatCap);
    painter->setPen(pen);

    // draw the notes including stem, (optional) flag and (optional) ledger line
    for (const auto& p : data->notesData) {
        const BagpipeEmbellishment::LayoutData::NoteData& noteData = p.second;

        // Draw Grace Note
        {
            // draw head
            item->drawSymbol(data->headsym, painter, noteData.headXY);

            // draw stem
            painter->drawLine(noteData.stemLine);

            if (data->isDrawFlag) {
                // draw flag
                item->drawSymbol(data->flagsym, painter, noteData.flagXY);
            }
        }

        // draw the ledger line for high A
        if (!noteData.ledgerLine.isNull()) {
            painter->drawLine(noteData.ledgerLine);
        }
    }

    if (data->isDrawBeam) {
        Pen beamPen(item->curColor(), dataBeam.width, PenStyle::SolidLine, PenCapStyle::FlatCap);
        painter->setPen(beamPen);
        // draw the beams
        auto drawBeams = [](mu::draw::Painter* painter, const double spatium,
                            const double x1, const double x2, double y)
        {
            // draw the beams
            painter->drawLine(mu::LineF(x1, y, x2, y));
            y += spatium / 1.5;
            painter->drawLine(mu::LineF(x1, y, x2, y));
            y += spatium / 1.5;
            painter->drawLine(mu::LineF(x1, y, x2, y));
        };

        drawBeams(painter, data->spatium, dataBeam.x1, dataBeam.x2, dataBeam.y);
    }
}

static void drawDots(const BarLine* item, Painter* painter, double x)
{
    double spatium = item->spatium();

    double y1l = 1.5 * spatium;
    double y2l = 2.5 * spatium;

    item->drawSymbol(SymId::repeatDot, painter, PointF(x, y1l));
    item->drawSymbol(SymId::repeatDot, painter, PointF(x, y2l));
}

static void drawTips(const BarLine* item, Painter* painter, bool reversed, double x)
{
    if (reversed) {
        if (item->isTop()) {
            item->drawSymbol(SymId::reversedBracketTop, painter, PointF(x - item->symWidth(SymId::reversedBracketTop), item->y1()));
        }
        if (item->isBottom()) {
            item->drawSymbol(SymId::reversedBracketBottom, painter, PointF(x - item->symWidth(SymId::reversedBracketBottom), item->y2()));
        }
    } else {
        if (item->isTop()) {
            item->drawSymbol(SymId::bracketTop, painter, PointF(x, item->y1()));
        }
        if (item->isBottom()) {
            item->drawSymbol(SymId::bracketBottom, painter, PointF(x, item->y2()));
        }
    }
}

void SingleDraw::draw(const BarLine* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    switch (item->barLineType()) {
    case BarLineType::NORMAL: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(lw * .5, item->y1(), lw * .5, item->y2()));
    }
    break;

    case BarLineType::BROKEN: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::DashLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(lw * .5, item->y1(), lw * .5, item->y2()));
    }
    break;

    case BarLineType::DOTTED: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::DotLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(lw * .5, item->y1(), lw * .5, item->y2()));
    }
    break;

    case BarLineType::END: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        double x  = lw * .5;
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        double lw2 = item->style().styleMM(Sid::endBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        x += ((lw * .5) + item->style().styleMM(Sid::endBarDistance) + (lw2 * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
    }
    break;

    case BarLineType::DOUBLE: {
        double lw = item->style().styleMM(Sid::doubleBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        double x = lw * .5;
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
        x += ((lw * .5) + item->style().styleMM(Sid::doubleBarDistance) + (lw * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
    }
    break;

    case BarLineType::REVERSE_END: {
        double lw = item->style().styleMM(Sid::endBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        double x = lw * .5;
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        double lw2 = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        x += ((lw * .5) + item->style().styleMM(Sid::endBarDistance) + (lw2 * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
    }
    break;

    case BarLineType::HEAVY: {
        double lw = item->style().styleMM(Sid::endBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(lw * .5, item->y1(), lw * .5, item->y2()));
    }
    break;

    case BarLineType::DOUBLE_HEAVY: {
        double lw2 = item->style().styleMM(Sid::endBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        double x = lw2 * .5;
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
        x += ((lw2 * .5) + item->style().styleMM(Sid::endBarDistance) + (lw2 * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));
    }
    break;

    case BarLineType::START_REPEAT: {
        double lw2 = item->style().styleMM(Sid::endBarWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        double x = lw2 * .5;
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        x += ((lw2 * .5) + item->style().styleMM(Sid::endBarDistance) + (lw * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        x += ((lw * .5) + item->style().styleMM(Sid::repeatBarlineDotSeparation)) * item->mag();
        drawDots(item, painter, x);

        if (item->style().styleB(Sid::repeatBarTips)) {
            drawTips(item, painter, false, 0.0);
        }
    }
    break;

    case BarLineType::END_REPEAT: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));

        double x = 0.0;
        drawDots(item, painter, x);

        x += item->symBbox(SymId::repeatDot).width();
        x += (item->style().styleMM(Sid::repeatBarlineDotSeparation) + (lw * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        double lw2 = item->style().styleMM(Sid::endBarWidth) * item->mag();
        x += ((lw * .5) + item->style().styleMM(Sid::endBarDistance) + (lw2 * .5)) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        if (item->style().styleB(Sid::repeatBarTips)) {
            drawTips(item, painter, true, x + lw2 * .5);
        }
    }
    break;
    case BarLineType::END_START_REPEAT: {
        double lw = item->style().styleMM(Sid::barWidth) * item->mag();
        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));

        double x = 0.0;
        drawDots(item, painter, x);

        x += item->symBbox(SymId::repeatDot).width();
        x += (item->style().styleMM(Sid::repeatBarlineDotSeparation) + (lw * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        double lw2 = item->style().styleMM(Sid::endBarWidth) * item->mag();
        x += ((lw * .5) + item->style().styleMM(Sid::endBarDistance) + (lw2 * .5)) * item->mag();
        painter->setPen(Pen(item->curColor(), lw2, PenStyle::SolidLine, PenCapStyle::FlatCap));
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        if (item->style().styleB(Sid::repeatBarTips)) {
            drawTips(item, painter, true, x + lw2 * .5);
        }

        painter->setPen(Pen(item->curColor(), lw, PenStyle::SolidLine, PenCapStyle::FlatCap));
        x  += ((lw2 * .5) + item->style().styleMM(Sid::endBarDistance) + (lw * .5)) * item->mag();
        painter->drawLine(LineF(x, item->y1(), x, item->y2()));

        x += ((lw * .5) + item->style().styleMM(Sid::repeatBarlineDotSeparation)) * item->mag();
        drawDots(item, painter, x);

        if (item->style().styleB(Sid::repeatBarTips)) {
            drawTips(item, painter, false, 0.0);
        }
    }
    break;
    }
}

void SingleDraw::draw(const Beam* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (item->beamSegments().empty()) {
        return;
    }
    painter->setBrush(Brush(item->curColor()));
    painter->setNoPen();

    // make beam thickness independent of slant
    // (expression can be simplified?)

    const LineF bs = item->beamSegments().front()->line;
    double d  = (std::abs(bs.y2() - bs.y1())) / (bs.x2() - bs.x1());
    if (item->beamSegments().size() > 1 && d > M_PI / 6.0) {
        d = M_PI / 6.0;
    }
    double ww = (item->beamWidth() / 2.0) / sin(M_PI_2 - atan(d));

    for (const BeamSegment* bs1 : item->beamSegments()) {
        painter->drawPolygon(
            PolygonF({
            PointF(bs1->line.x1(), bs1->line.y1() - ww),
            PointF(bs1->line.x2(), bs1->line.y2() - ww),
            PointF(bs1->line.x2(), bs1->line.y2() + ww),
            PointF(bs1->line.x1(), bs1->line.y1() + ww),
        }),
            draw::FillRule::OddEvenFill);
    }
}

void SingleDraw::draw(const Bend* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    double _spatium = item->spatium();
    double _lw = item->lineWidth();

    Pen pen(item->curColor(), _lw, PenStyle::SolidLine, PenCapStyle::RoundCap, PenJoinStyle::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(Brush(item->curColor()));

    mu::draw::Font f = item->font(_spatium * MScore::pixelRatio);
    painter->setFont(f);

    double x  = item->noteWidth() + _spatium * .2;
    double y  = -_spatium * .8;
    double x2, y2;

    double aw = item->style().styleMM(Sid::bendArrowWidth);
    PolygonF arrowUp;
    arrowUp << PointF(0, 0) << PointF(aw * .5, aw) << PointF(-aw * .5, aw);
    PolygonF arrowDown;
    arrowDown << PointF(0, 0) << PointF(aw * .5, -aw) << PointF(-aw * .5, -aw);

    size_t n = item->points().size();
    for (size_t pt = 0; pt < n - 1; ++pt) {
        int pitch = item->points()[pt].pitch;
        if (pt == 0 && pitch) {
            y2 = -item->notePos().y() - _spatium * 2;
            x2 = x;
            painter->drawLine(LineF(x, y, x2, y2));

            painter->setBrush(item->curColor());
            painter->drawPolygon(arrowUp.translated(x2, y2));

            int idx = (pitch + 12) / 25;
            const char* l = item->label[idx];
            painter->drawText(RectF(x2, y2, .0, .0),
                              draw::AlignHCenter | draw::AlignBottom | draw::TextDontClip,
                              String::fromAscii(l));

            y = y2;
        }
        if (pitch == item->points()[pt + 1].pitch) {
            if (pt == (n - 2)) {
                break;
            }
            x2 = x + _spatium;
            y2 = y;
            painter->drawLine(LineF(x, y, x2, y2));
        } else if (pitch < item->points()[pt + 1].pitch) {
            // up
            x2 = x + _spatium * .5;
            y2 = -item->notePos().y() - _spatium * 2;
            double dx = x2 - x;
            double dy = y2 - y;

            PainterPath path;
            path.moveTo(x, y);
            path.cubicTo(x + dx / 2, y, x2, y + dy / 4, x2, y2);
            painter->setBrush(BrushStyle::NoBrush);
            painter->drawPath(path);

            painter->setBrush(item->curColor());
            painter->drawPolygon(arrowUp.translated(x2, y2));

            int idx = (item->points()[pt + 1].pitch + 12) / 25;
            const char* l = item->label[idx];
            double ty = y2;       // - _spatium;
            painter->drawText(RectF(x2, ty, .0, .0),
                              draw::AlignHCenter | draw::AlignBottom | draw::TextDontClip,
                              String::fromAscii(l));
        } else {
            // down
            x2 = x + _spatium * .5;
            y2 = y + _spatium * 3;
            double dx = x2 - x;
            double dy = y2 - y;

            PainterPath path;
            path.moveTo(x, y);
            path.cubicTo(x + dx / 2, y, x2, y + dy / 4, x2, y2);
            painter->setBrush(BrushStyle::NoBrush);
            painter->drawPath(path);

            painter->setBrush(item->curColor());
            painter->drawPolygon(arrowDown.translated(x2, y2));
        }
        x = x2;
        y = y2;
    }
}

void SingleDraw::draw(const Bracket* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (RealIsNull(item->h2())) {
        return;
    }
    switch (item->bracketType()) {
    case BracketType::BRACE: {
        if (item->braceSymbol() == SymId::noSym) {
            painter->setNoPen();
            painter->setBrush(Brush(item->curColor()));
            painter->drawPath(item->path());
        } else {
            double h        = 2 * item->h2();
            double mag      = h / (100 * item->magS());
            painter->setPen(item->curColor());
            painter->save();
            painter->scale(item->magx(), mag);
            item->drawSymbol(item->braceSymbol(), painter, PointF(0, 100 * item->magS()));
            painter->restore();
        }
    }
    break;
    case BracketType::NORMAL: {
        double h        = 2 * item->h2();
        double _spatium = item->spatium();
        double w        = item->style().styleMM(Sid::bracketWidth);
        double bd       = (item->style().styleSt(Sid::MusicalSymbolFont) == "Leland") ? _spatium * .5 : _spatium * .25;
        Pen pen(item->curColor(), w, PenStyle::SolidLine, PenCapStyle::FlatCap);
        painter->setPen(pen);
        painter->drawLine(LineF(0.0, -bd - w * .5, 0.0, h + bd + w * .5));
        double x    =  -w * .5;
        double y1   = -bd;
        double y2   = h + bd;
        item->drawSymbol(SymId::bracketTop, painter, PointF(x, y1));
        item->drawSymbol(SymId::bracketBottom, painter, PointF(x, y2));
    }
    break;
    case BracketType::SQUARE: {
        double h = 2 * item->h2();
        double lineW = item->style().styleMM(Sid::staffLineWidth);
        double bracketWidth = item->width() - lineW / 2;
        Pen pen(item->curColor(), lineW, PenStyle::SolidLine, PenCapStyle::FlatCap);
        painter->setPen(pen);
        painter->drawLine(LineF(0.0, 0.0, 0.0, h));
        painter->drawLine(LineF(-lineW / 2, 0.0, lineW / 2 + bracketWidth, 0.0));
        painter->drawLine(LineF(-lineW / 2, h, lineW / 2 + bracketWidth, h));
    }
    break;
    case BracketType::LINE: {
        double h = 2 * item->h2();
        double w = 0.67 * item->style().styleMM(Sid::bracketWidth);
        Pen pen(item->curColor(), w, PenStyle::SolidLine, PenCapStyle::FlatCap);
        painter->setPen(pen);
        double bd = item->style().styleMM(Sid::staffLineWidth) * 0.5;
        painter->drawLine(LineF(0.0, -bd, 0.0, h + bd));
    }
    break;
    case BracketType::NO_BRACKET:
        break;
    }
}

void SingleDraw::draw(const Breath* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setPen(item->curColor());
    item->drawSymbol(item->symId(), painter);
}

void SingleDraw::draw(const ChordLine* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    const ChordLine::LayoutData* ldata = item->layoutData();
    IF_ASSERT_FAILED(ldata) {
        return;
    }

    if (!item->isWavy()) {
        painter->setPen(Pen(item->curColor(), item->style().styleMM(Sid::chordlineThickness) * item->mag(), PenStyle::SolidLine));
        painter->setBrush(BrushStyle::NoBrush);
        painter->drawPath(ldata->path);
    } else {
        painter->save();
        painter->rotate((item->chordLineType() == ChordLineType::FALL ? 1 : -1) * ChordLine::WAVE_ANGEL);
        item->drawSymbols(ChordLine::WAVE_SYMBOLS, painter);
        painter->restore();
    }
}

void SingleDraw::draw(const Clef* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    const Clef::LayoutData* ldata = item->layoutData();
    IF_ASSERT_FAILED(ldata) {
        return;
    }

    if (ldata->symId == SymId::noSym) {
        return;
    }
    painter->setPen(item->curColor());
    item->drawSymbol(ldata->symId, painter);
}

void SingleDraw::draw(const Capo* item, Painter* painter)
{
    drawTextBase(item, painter);
}

void SingleDraw::draw(const DeadSlapped* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    const DeadSlapped::LayoutData* ldata = item->layoutData();
    IF_ASSERT_FAILED(ldata) {
        return;
    }

    painter->setPen(draw::PenStyle::NoPen);
    painter->setBrush(item->curColor());
    painter->drawPath(ldata->path1);
    painter->drawPath(ldata->path2);
}

void SingleDraw::draw(const Dynamic* item, Painter* painter)
{
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Expression* item, Painter* painter)
{
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Fermata* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setPen(item->curColor());
    item->drawSymbol(item->symId(), painter, PointF(-0.5 * item->width(), 0.0));
}

void SingleDraw::draw(const FiguredBass* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (item->items().size() < 1) {                                 // if not parseable into f.b. items
        drawTextBase(item, painter);                                // draw as standard text
    } else {
        for (FiguredBassItem* fi : item->items()) {               // if parseable into f.b. items
            painter->translate(fi->pos());                // draw each item in its proper position
            draw(fi, painter);
            painter->translate(-fi->pos());
        }
    }
}

void SingleDraw::draw(const FiguredBassItem* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    int font = 0;
    double _spatium = item->spatium();
    // set font from general style
    mu::draw::Font f(FiguredBass::FBFonts().at(font).family, draw::Font::Type::Tablature);

    // (use the same font selection as used in layout() above)
    double m = item->style().styleD(Sid::figuredBassFontSize) * item->spatium() / SPATIUM20;
    f.setPointSizeF(m * MScore::pixelRatio);

    painter->setFont(f);
    painter->setBrush(BrushStyle::NoBrush);
    Pen pen(item->figuredBass()->curColor(), FiguredBass::FB_CONTLINE_THICKNESS * _spatium, PenStyle::SolidLine, PenCapStyle::RoundCap);
    painter->setPen(pen);
    painter->drawText(item->bbox(), draw::TextDontClip | draw::AlignLeft | draw::AlignTop, item->displayText());

    // continuation line
    double lineEndX = 0.0;
    if (item->contLine() != FiguredBassItem::ContLine::NONE) {
        double lineStartX  = item->textWidth();                           // by default, line starts right after text
        if (lineStartX > 0.0) {
            lineStartX += _spatium * FiguredBass::FB_CONTLINE_LEFT_PADDING;          // if some text, give some room after it
        }
        lineEndX = item->figuredBass()->printedLineLength();            // by default, line ends with item duration
        if (lineEndX - lineStartX < 1.0) {                         // if line length < 1 sp, ignore it
            lineEndX = 0.0;
        }

        // if extended cont.line and no closing parenthesis: look at next FB element
        if (item->contLine() > FiguredBassItem::ContLine::SIMPLE && item->parenth5() == FiguredBassItem::Parenthesis::NONE) {
            FiguredBass* nextFB;
            // if there is a contiguous FB element
            if ((nextFB = item->figuredBass()->nextFiguredBass()) != 0) {
                // retrieve the X position (in page coords) of a possible cont. line of nextFB
                // on the same line of 'this'
                PointF pgPos = item->pagePos();
                double nextContPageX = nextFB->additionalContLineX(pgPos.y());
                // if an additional cont. line has been found, extend up to its initial X coord
                if (nextContPageX > 0) {
                    lineEndX = nextContPageX - pgPos.x() + _spatium * FiguredBass::FB_CONTLINE_OVERLAP;
                }
                // with a little bit of overlap
                else {
                    lineEndX = item->figuredBass()->lineLength(0);                  // if none found, draw to the duration end
                }
            }
        }
        // if some line, draw it
        if (lineEndX > 0.0) {
            double h = item->bbox().height() * FiguredBass::FB_CONTLINE_HEIGHT;
            painter->drawLine(lineStartX, h, lineEndX - item->ipos().x(), h);
        }
    }

    // closing cont.line parenthesis
    if (item->parenth5() != FiguredBassItem::Parenthesis::NONE) {
        int x = lineEndX > 0.0 ? lineEndX : item->textWidth();
        painter->drawText(RectF(x, 0, item->bbox().width(), item->bbox().height()), draw::AlignLeft | draw::AlignTop,
                          Char(FiguredBass::FBFonts().at(font).displayParenthesis[int(item->parenth5())].unicode()));
    }
}

void SingleDraw::draw(const Fingering* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const FretDiagram* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    PointF translation = -PointF(item->stringDist() * (item->strings() - 1), 0);
    if (item->orientation() == Orientation::HORIZONTAL) {
        painter->save();
        painter->rotate(-90);
        painter->translate(translation);
    }

    // Init pen and other values
    double _spatium = item->spatium() * item->userMag();
    Pen pen(item->curColor());
    pen.setCapStyle(PenCapStyle::FlatCap);
    painter->setBrush(Brush(Color(painter->pen().color())));

    // x2 is the x val of the rightmost string
    double x2 = (item->strings() - 1) * item->stringDist();

    // Draw the nut
    pen.setWidthF(item->nutLw());
    painter->setPen(pen);
    painter->drawLine(LineF(-item->stringLw() * .5, 0.0, x2 + item->stringLw() * .5, 0.0));

    // Draw strings and frets
    pen.setWidthF(item->stringLw());
    painter->setPen(pen);

    // y2 is the y val of the bottom fretline
    double y2 = item->fretDist() * (item->frets() + .5);
    for (int i = 0; i < item->strings(); ++i) {
        double x = item->stringDist() * i;
        painter->drawLine(LineF(x, item->fretOffset() ? -_spatium * .2 : 0.0, x, y2));
    }
    for (int i = 1; i <= item->frets(); ++i) {
        double y = item->fretDist() * i;
        painter->drawLine(LineF(0.0, y, x2, y));
    }

    // dotd is the diameter of a dot
    double dotd = _spatium * .49 * item->style().styleD(Sid::fretDotSize);

    // Draw dots, sym pen is used to draw them (and markers)
    Pen symPen(pen);
    symPen.setCapStyle(PenCapStyle::RoundCap);
    double symPenWidth = item->stringLw() * 1.2;
    symPen.setWidthF(symPenWidth);

    for (auto const& i : item->dots()) {
        for (auto const& d : i.second) {
            if (!d.exists()) {
                continue;
            }

            int string = i.first;
            int fret = d.fret - 1;

            // Calculate coords of the top left corner of the dot
            double x = item->stringDist() * string - dotd * .5;
            double y = item->fretDist() * fret + item->fretDist() * .5 - dotd * .5;

            // Draw different symbols
            painter->setPen(symPen);
            switch (d.dtype) {
            case FretDotType::CROSS:
                // Give the cross a slightly larger width
                symPen.setWidthF(symPenWidth * 1.5);
                painter->setPen(symPen);
                painter->drawLine(LineF(x, y, x + dotd, y + dotd));
                painter->drawLine(LineF(x + dotd, y, x, y + dotd));
                symPen.setWidthF(symPenWidth);
                break;
            case FretDotType::SQUARE:
                painter->setBrush(BrushStyle::NoBrush);
                painter->drawRect(RectF(x, y, dotd, dotd));
                break;
            case FretDotType::TRIANGLE:
                painter->drawLine(LineF(x, y + dotd, x + .5 * dotd, y));
                painter->drawLine(LineF(x + .5 * dotd, y, x + dotd, y + dotd));
                painter->drawLine(LineF(x + dotd, y + dotd, x, y + dotd));
                break;
            case FretDotType::NORMAL:
            default:
                painter->setBrush(symPen.color());
                painter->setNoPen();
                painter->drawEllipse(RectF(x, y, dotd, dotd));
                break;
            }
        }
    }

    // Draw markers
    symPen.setWidthF(symPenWidth * 1.2);
    painter->setBrush(BrushStyle::NoBrush);
    painter->setPen(symPen);
    for (auto const& i : item->markers()) {
        int string = i.first;
        FretItem::Marker marker = i.second;
        if (!marker.exists()) {
            continue;
        }

        double x = item->stringDist() * string - item->markerSize() * .5;
        double y = -item->fretDist() - item->markerSize() * .5;
        if (marker.mtype == FretMarkerType::CIRCLE) {
            painter->drawEllipse(RectF(x, y, item->markerSize(), item->markerSize()));
        } else if (marker.mtype == FretMarkerType::CROSS) {
            painter->drawLine(PointF(x, y), PointF(x + item->markerSize(), y + item->markerSize()));
            painter->drawLine(PointF(x, y + item->markerSize()), PointF(x + item->markerSize(), y));
        }
    }

    // Draw barres
    for (auto const& i : item->barres()) {
        int fret        = i.first;
        int startString = i.second.startString;
        int endString   = i.second.endString;

        double x1    = item->stringDist() * startString;
        double newX2 = endString == -1 ? x2 : item->stringDist() * endString;
        double y     = item->fretDist() * (fret - 1) + item->fretDist() * .5;
        pen.setWidthF(dotd * item->style().styleD(Sid::barreLineWidth));
        pen.setCapStyle(PenCapStyle::RoundCap);
        painter->setPen(pen);
        painter->drawLine(LineF(x1, y, newX2, y));
    }

    // Draw fret offset number
    if (item->fretOffset() > 0) {
        double fretNumMag = item->style().styleD(Sid::fretNumMag);
        mu::draw::Font scaledFont(item->font());
        scaledFont.setPointSizeF(item->font().pointSizeF()
                                 * item->userMag()
                                 * (item->spatium() / SPATIUM20)
                                 * MScore::pixelRatio
                                 * fretNumMag);
        painter->setFont(scaledFont);
        String text = String::number(item->fretOffset() + 1);

        if (item->orientation() == Orientation::VERTICAL) {
            if (item->numPos() == 0) {
                painter->drawText(RectF(-item->stringDist() * .4, .0, .0, item->fretDist()),
                                  draw::AlignVCenter | draw::AlignRight | draw::TextDontClip, text);
            } else {
                painter->drawText(RectF(x2 + (item->stringDist() * .4), .0, .0, item->fretDist()),
                                  draw::AlignVCenter | draw::AlignLeft | draw::TextDontClip,
                                  String::number(item->fretOffset() + 1));
            }
        } else if (item->orientation() == Orientation::HORIZONTAL) {
            painter->save();
            painter->translate(-translation);
            painter->rotate(90);
            if (item->numPos() == 0) {
                painter->drawText(RectF(.0, item->stringDist() * (item->strings() - 1), .0, .0),
                                  draw::AlignLeft | draw::TextDontClip, text);
            } else {
                painter->drawText(RectF(.0, .0, .0, .0), draw::AlignBottom | draw::AlignLeft | draw::TextDontClip, text);
            }
            painter->restore();
        }
        painter->setFont(item->font());
    }

    // NOTE:JT possible future todo - draw fingerings

    if (item->orientation() == Orientation::HORIZONTAL) {
        painter->restore();
    }
}

void SingleDraw::draw(const GlissandoSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (item->pos2().x() <= 0) {
        return;
    }

    painter->save();
    double _spatium = item->spatium();
    const Glissando* glissando = item->glissando();

    Pen pen(item->curColor(item->visible(), glissando->lineColor()));
    pen.setWidthF(glissando->lineWidth());
    pen.setCapStyle(PenCapStyle::RoundCap);
    painter->setPen(pen);

    // rotate painter so that the line become horizontal
    double w     = item->pos2().x();
    double h     = item->pos2().y();
    double l     = sqrt(w * w + h * h);
    double wi    = asin(-h / l) * 180.0 / M_PI;
    painter->rotate(-wi);

    if (glissando->glissandoType() == GlissandoType::STRAIGHT) {
        painter->drawLine(LineF(0.0, 0.0, l, 0.0));
    } else if (glissando->glissandoType() == GlissandoType::WAVY) {
        RectF b = item->symBbox(SymId::wiggleTrill);
        double a  = item->symAdvance(SymId::wiggleTrill);
        int n    = static_cast<int>(l / a);          // always round down (truncate) to avoid overlap
        double x  = (l - n * a) * 0.5;     // centre line in available space
        SymIdList ids;
        for (int i = 0; i < n; ++i) {
            ids.push_back(SymId::wiggleTrill);
        }

        item->drawSymbols(ids, painter, PointF(x, -(b.y() + b.height() * 0.5)));
    }

    if (glissando->showText()) {
        mu::draw::Font f(glissando->fontFace(), draw::Font::Type::Unknown);
        f.setPointSizeF(glissando->fontSize() * _spatium / SPATIUM20);
        f.setBold(glissando->fontStyle() & FontStyle::Bold);
        f.setItalic(glissando->fontStyle() & FontStyle::Italic);
        f.setUnderline(glissando->fontStyle() & FontStyle::Underline);
        f.setStrike(glissando->fontStyle() & FontStyle::Strike);
        mu::draw::FontMetrics fm(f);
        RectF r = fm.boundingRect(glissando->text());

        // if text longer than available space, skip it
        if (r.width() < l) {
            double yOffset = r.height() + r.y();             // find text descender height
            // raise text slightly above line and slightly more with WAVY than with STRAIGHT
            yOffset += _spatium * (glissando->glissandoType() == GlissandoType::WAVY ? 0.4 : 0.1);

            mu::draw::Font scaledFont(f);
            scaledFont.setPointSizeF(f.pointSizeF() * MScore::pixelRatio);
            painter->setFont(scaledFont);

            double x = (l - r.width()) * 0.5;
            painter->drawText(PointF(x, -yOffset), glissando->text());
        }
    }
    painter->restore();
}

void SingleDraw::draw(const Stem* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (!item->chord()) { // may be need assert?
        return;
    }

    // hide if second chord of a cross-measure pair
    if (item->chord()->crossMeasure() == CrossMeasure::SECOND) {
        return;
    }

    const Staff* staff = item->staff();
    const StaffType* staffType = staff ? staff->staffTypeForElement(item->chord()) : nullptr;
    const bool isTablature = staffType && staffType->isTabStaff();

    painter->setPen(Pen(item->curColor(), item->lineWidthMag(), PenStyle::SolidLine, PenCapStyle::FlatCap));
    painter->drawLine(item->line());

    if (!isTablature) {
        return;
    }

    // TODO: adjust bounding rectangle in layout() for dots and for slash
    double sp = item->spatium();
    bool isUp = item->up();

    // slashed half note stem
    if (item->chord()->durationType().type() == DurationType::V_HALF
        && staffType->minimStyle() == TablatureMinimStyle::SLASHED) {
        // position slashes onto stem
        double y = isUp ? -item->length() + STAFFTYPE_TAB_SLASH_2STARTY_UP * sp
                   : item->length() - STAFFTYPE_TAB_SLASH_2STARTY_DN * sp;
        // if stems through, try to align slashes within or across lines
        if (staffType->stemThrough()) {
            double halfLineDist = staffType->lineDistance().val() * sp * 0.5;
            double halfSlashHgt = STAFFTYPE_TAB_SLASH_2TOTHEIGHT * sp * 0.5;
            y = lrint((y + halfSlashHgt) / halfLineDist) * halfLineDist - halfSlashHgt;
        }
        // draw slashes
        double hlfWdt= sp * STAFFTYPE_TAB_SLASH_WIDTH * 0.5;
        double sln   = sp * STAFFTYPE_TAB_SLASH_SLANTY;
        double thk   = sp * STAFFTYPE_TAB_SLASH_THICK;
        double displ = sp * STAFFTYPE_TAB_SLASH_DISPL;
        PainterPath path;
        for (int i = 0; i < 2; ++i) {
            path.moveTo(hlfWdt, y);                   // top-right corner
            path.lineTo(hlfWdt, y + thk);             // bottom-right corner
            path.lineTo(-hlfWdt, y + thk + sln);      // bottom-left corner
            path.lineTo(-hlfWdt, y + sln);            // top-left corner
            path.closeSubpath();
            y += displ;
        }
        painter->setBrush(Brush(item->curColor()));
        painter->setNoPen();
        painter->drawPath(path);
    }

    // dots
    // NOT THE BEST PLACE FOR THIS?
    // with tablatures and stems beside staves, dots are not drawn near 'notes', but near stems
    int nDots = item->chord()->dots();
    if (nDots > 0 && !staffType->stemThrough()) {
        double x     = item->chord()->dotPosX();
        double y     = ((STAFFTYPE_TAB_DEFAULTSTEMLEN_DN * 0.2) * sp) * (isUp ? -1.0 : 1.0);
        double step  = item->style().styleS(Sid::dotDotDistance).val() * sp;
        for (int dot = 0; dot < nDots; dot++, x += step) {
            item->drawSymbol(SymId::augmentationDot, painter, PointF(x, y));
        }
    }
}

void SingleDraw::draw(const StemSlash* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    painter->setPen(Pen(item->curColor(), item->stemWidth(), PenStyle::SolidLine, PenCapStyle::FlatCap));
    painter->drawLine(item->line());
}

void SingleDraw::draw(const Sticking* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const StretchedBend* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    double sp = item->spatium();
    const mu::draw::Color& color = item->curColor();
    const int textFlags = item->textFlags();

    Pen pen(color, item->lineWidth(), PenStyle::SolidLine, PenCapStyle::RoundCap, PenJoinStyle::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(Brush(color));
    mu::draw::Font f = item->font(sp * MScore::pixelRatio);
    painter->setFont(f);

    bool isTextDrawn = false;

    for (const StretchedBend::BendSegment& bendSegment : item->bendSegmentsStretched()) {
        if (!bendSegment.visible) {
            continue;
        }

        const PointF& src = bendSegment.src;
        const PointF& dest = bendSegment.dest;
        const String& text = item->toneToLabel(bendSegment.tone);

        switch (bendSegment.type) {
        case StretchedBend::BendSegmentType::LINE_UP:
        {
            painter->drawLine(LineF(src, dest));
            painter->setBrush(color);
            painter->drawPolygon(item->arrows().up.translated(dest));
            /// TODO: remove substraction after fixing bRect
            PointF pos = dest - PointF(0, sp * 0.5);
            painter->drawText(RectF(pos.x(), pos.y(), .0, .0), textFlags, text);
            break;
        }

        case StretchedBend::BendSegmentType::CURVE_UP:
        case StretchedBend::BendSegmentType::CURVE_DOWN:
        {
            bool bendUp = (bendSegment.type == StretchedBend::BendSegmentType::CURVE_UP);
            double endY = dest.y() + item->arrows().width * (bendUp ? 1 : -1);

            PainterPath path = item->bendCurveFromPoints(src, PointF(dest.x(), endY));
            const auto& arrowPath = (bendUp ? item->arrows().up : item->arrows().down);

            painter->setBrush(BrushStyle::NoBrush);
            painter->drawPath(path);
            painter->setBrush(color);
            painter->drawPolygon(arrowPath.translated(dest));

            if (bendUp && !isTextDrawn) {
                /// TODO: remove subtraction after fixing bRect
                PointF pos = dest - PointF(0, sp * 0.5);
                painter->drawText(RectF(pos.x(), pos.y(), .0, .0), textFlags, text);
                isTextDrawn = true;
            }

            break;
        }

        case StretchedBend::BendSegmentType::LINE_STROKED:
        {
            PainterPath path;
            path.moveTo(src + PointF(item->arrows().width, 0));
            path.lineTo(dest);
            Pen p(painter->pen());
            p.setStyle(PenStyle::DashLine);
            painter->strokePath(path, p);
            break;
        }

        default:
            break;
        }
    }
}

void SingleDraw::drawTextBase(const TextBase* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (item->hasFrame()) {
        double baseSpatium = DefaultStyle::baseStyle().value(Sid::spatium).toReal();
        if (item->frameWidth().val() != 0.0) {
            Color fColor = item->curColor(item->visible(), item->frameColor());
            double frameWidthVal = item->frameWidth().val() * (item->sizeIsSpatiumDependent() ? item->spatium() : baseSpatium);

            Pen pen(fColor, frameWidthVal, PenStyle::SolidLine, PenCapStyle::SquareCap, PenJoinStyle::MiterJoin);
            painter->setPen(pen);
        } else {
            painter->setNoPen();
        }
        Color bg(item->bgColor());
        painter->setBrush(bg.alpha() ? Brush(bg) : BrushStyle::NoBrush);
        if (item->circle()) {
            painter->drawEllipse(item->frame());
        } else {
            double frameRoundFactor = (item->sizeIsSpatiumDependent() ? (item->spatium() / baseSpatium) / 2 : 0.5f);

            int r2 = item->frameRound() * frameRoundFactor;
            if (r2 > 99) {
                r2 = 99;
            }
            painter->drawRoundedRect(item->frame(), item->frameRound() * frameRoundFactor, r2);
        }
    }
    painter->setBrush(BrushStyle::NoBrush);
    painter->setPen(item->textColor());
    for (const TextBlock& t : item->blocks()) {
        t.draw(painter, item);
    }
}

void SingleDraw::drawTextLineBaseSegment(const TextLineBaseSegment* item, Painter* painter)
{
    const TextLineBase* tl = item->textLineBase();

    if (!item->text()->empty()) {
        painter->translate(item->text()->pos());
        item->text()->setVisible(tl->visible());
        draw(item->text(), painter);
        painter->translate(-item->text()->pos());
    }

    if (!item->endText()->empty()) {
        painter->translate(item->endText()->pos());
        item->endText()->setVisible(tl->visible());
        draw(item->endText(), painter);
        painter->translate(-item->endText()->pos());
    }

    if (item->npoints() == 0) {
        return;
    }

    // color for line (text color comes from the text properties)
    Color color = item->curColor(tl->visible() && tl->lineVisible(), tl->lineColor());

    double lineWidth = tl->lineWidth() * item->mag();

    const Pen solidPen(color, lineWidth, PenStyle::SolidLine, PenCapStyle::FlatCap, PenJoinStyle::MiterJoin);
    Pen pen(solidPen);

    double dash = 0;
    double gap = 0;

    switch (tl->lineStyle()) {
    case LineType::SOLID:
        break;
    case LineType::DASHED:
        dash = tl->dashLineLen(), gap = tl->dashGapLen();
        break;
    case LineType::DOTTED:
        dash = 0.01, gap = 1.99;
        pen.setCapStyle(PenCapStyle::RoundCap); // round dots
        break;
    }

    const bool isNonSolid = tl->lineStyle() != LineType::SOLID;

    // Draw lines
    if (item->twoLines()) { // hairpins
        if (isNonSolid) {
            pen.setDashPattern({ dash, gap });
        }

        pen.setJoinStyle(PenJoinStyle::BevelJoin);
        painter->setPen(pen);
        if (!item->joinedHairpin().empty() && !isNonSolid) {
            painter->drawPolyline(item->joinedHairpin());
        } else {
            painter->drawLines(&item->points()[0], 2);
        }
        return;
    }

    auto distributedDashPattern = [](double dash, double gap, double lineLength) -> std::vector<double>
    {
        int numPairs = std::max(1.0, lineLength / (dash + gap));
        double newGap = (lineLength - dash * (numPairs + 1)) / numPairs;

        return { dash, newGap };
    };

    int start = 0, end = item->npoints();

    // Draw begin hook, if it needs to be drawn separately
    if (item->isSingleBeginType() && tl->beginHookType() != HookType::NONE) {
        bool isTHook = tl->beginHookType() == HookType::HOOK_90T;

        if (isNonSolid || isTHook) {
            const PointF& p1 = item->points()[start++];
            const PointF& p2 = item->points()[start++];

            if (isTHook) {
                painter->setPen(solidPen);
            } else {
                double hookLength = sqrt(PointF::dotProduct(p2 - p1, p2 - p1));
                pen.setDashPattern(distributedDashPattern(dash, gap, hookLength / lineWidth));
                painter->setPen(pen);
            }

            painter->drawLine(p1, p2);
        }
    }

    // Draw end hook, if it needs to be drawn separately
    if (item->isSingleEndType() && tl->endHookType() != HookType::NONE) {
        bool isTHook = tl->endHookType() == HookType::HOOK_90T;

        if (isNonSolid || isTHook) {
            const PointF& p1 = item->points()[--end];
            const PointF& p2 = item->points()[--end];

            if (isTHook) {
                painter->setPen(solidPen);
            } else {
                double hookLength = sqrt(PointF::dotProduct(p2 - p1, p2 - p1));
                pen.setDashPattern(distributedDashPattern(dash, gap, hookLength / lineWidth));
                painter->setPen(pen);
            }

            painter->drawLine(p1, p2);
        }
    }

    // Draw the rest
    if (isNonSolid) {
        pen.setDashPattern(distributedDashPattern(dash, gap, item->lineLength() / lineWidth));
    }

    painter->setPen(pen);
    painter->drawPolyline(&item->points()[start], end - start);
}

void SingleDraw::draw(const GradualTempoChangeSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const HairpinSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    drawTextLineBaseSegment(item, painter);

    if (item->drawCircledTip()) {
        Color color = item->curColor(item->hairpin()->visible(), item->hairpin()->lineColor());
        double w = item->hairpin()->lineWidth();
        if (item->staff()) {
            w *= item->staff()->staffMag(item->hairpin()->tick());
        }

        Pen pen(color, w);
        painter->setPen(pen);
        painter->setBrush(BrushStyle::NoBrush);
        painter->drawEllipse(item->circledTip(), item->circledTipRadius(), item->circledTipRadius());
    }
}

void SingleDraw::draw(const HarpPedalDiagram* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const HarmonicMarkSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const Harmony* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (item->isDrawEditMode()) {
        drawTextBase(item, painter);
        return;
    }

    if (item->textList().empty()) {
        drawTextBase(item, painter);
        return;
    }

    if (item->hasFrame()) {
        if (item->frameWidth().val() != 0.0) {
            Color color = item->frameColor();
            Pen pen(color, item->frameWidth().val() * item->spatium(), PenStyle::SolidLine,
                    PenCapStyle::SquareCap, PenJoinStyle::MiterJoin);
            painter->setPen(pen);
        } else {
            painter->setNoPen();
        }
        Color bg(item->bgColor());
        painter->setBrush(bg.alpha() ? Brush(bg) : BrushStyle::NoBrush);
        if (item->circle()) {
            painter->drawArc(item->frame(), 0, 5760);
        } else {
            int r2 = item->frameRound();
            if (r2 > 99) {
                r2 = 99;
            }
            painter->drawRoundedRect(item->frame(), item->frameRound(), r2);
        }
    }
    painter->setBrush(BrushStyle::NoBrush);
    Color color = item->textColor();
    painter->setPen(color);
    for (const TextSegment* ts : item->textList()) {
        mu::draw::Font f(ts->m_font);
        f.setPointSizeF(f.pointSizeF() * MScore::pixelRatio);
#ifndef Q_OS_MACOS
        TextBase::drawTextWorkaround(painter, f, ts->pos(), ts->text);
#else
        painter->setFont(f);
        painter->drawText(ts->pos(), ts->text);
#endif
    }
}

void SingleDraw::draw(const Hook* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setPen(item->curColor());
    item->drawSymbol(item->sym(), painter);
}

void SingleDraw::draw(const Image* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    bool emptyImage = false;
    if (item->imageType() == ImageType::SVG) {
        if (!item->svgRenderer()) {
            emptyImage = true;
        } else {
            item->svgRenderer()->render(painter, item->bbox());
        }
    } else if (item->imageType() == ImageType::RASTER) {
        if (item->rasterImage() == nullptr) {
            emptyImage = true;
        } else {
            painter->save();
            SizeF s;
            if (item->sizeIsSpatium()) {
                s = item->size() * item->spatium();
            } else {
                s = item->size() * DPMM;
            }

            Transform t = painter->worldTransform();
            Size ss = Size(s.width() * t.m11(), s.height() * t.m22());
            t.setMatrix(1.0, t.m12(), t.m13(), t.m21(), 1.0, t.m23(), t.m31(), t.m32(), t.m33());
            painter->setWorldTransform(t);
            if ((item->buffer().size() != ss || item->dirty()) && item->rasterImage() && !item->rasterImage()->isNull()) {
                item->setBuffer(item->imageProvider()->scaled(*item->rasterImage(), ss));
                item->setDirty(false);
            }
            if (item->buffer().isNull()) {
                emptyImage = true;
            } else {
                painter->drawPixmap(PointF(0.0, 0.0), item->buffer());
            }

            painter->restore();
        }
    }

    if (emptyImage) {
        painter->setBrush(mu::draw::BrushStyle::NoBrush);
        painter->setPen(item->engravingConfiguration()->defaultColor());
        painter->drawRect(item->bbox());
        painter->drawLine(0.0, 0.0, item->bbox().width(), item->bbox().height());
        painter->drawLine(item->bbox().width(), 0.0, 0.0, item->bbox().height());
    }
}

void SingleDraw::draw(const InstrumentChange* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const InstrumentName* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Jump* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const KeySig* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    painter->setPen(item->curColor());
    double _spatium = item->spatium();
    double step = _spatium * 0.5;
    int lines = 5;
    double ledgerLineWidth = item->style().styleMM(Sid::ledgerLineWidth) * item->mag();
    double ledgerExtraLen = item->style().styleS(Sid::ledgerLineLength).val() * _spatium;
    for (const KeySym& ks : item->keySymbols()) {
        double x = ks.xPos * _spatium;
        double y = ks.line * step;
        item->drawSymbol(ks.sym, painter, PointF(x, y));
        // ledger lines
        double _symWidth = item->symWidth(ks.sym);
        double x1 = x - ledgerExtraLen;
        double x2 = x + _symWidth + ledgerExtraLen;
        painter->setPen(Pen(item->curColor(), ledgerLineWidth, PenStyle::SolidLine, PenCapStyle::FlatCap));
        for (int i = -2; i >= ks.line; i -= 2) { // above
            y = i * step;
            painter->drawLine(LineF(x1, y, x2, y));
        }
        for (int i = lines * 2; i <= ks.line; i += 2) { // below
            y = i * step;
            painter->drawLine(LineF(x1, y, x2, y));
        }
    }

    if (!item->explicitParent() && (item->isAtonal() || item->isCustom()) && item->keySymbols().empty()) {
        // empty custom or atonal key signature - draw something for palette
        painter->setPen(item->engravingConfiguration()->formattingMarksColor());
        item->drawSymbol(SymId::timeSigX, painter, PointF(item->symWidth(SymId::timeSigX) * -0.5, 2.0 * item->spatium()));
    }
}

void SingleDraw::draw(const LayoutBreak* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    Pen pen;
    pen.setColor(item->engravingConfiguration()->fontPrimaryColor());
    pen.setWidthF(item->lineWidth() / 2);
    pen.setJoinStyle(PenJoinStyle::MiterJoin);
    pen.setCapStyle(PenCapStyle::SquareCap);
    pen.setDashPattern({ 1, 3 });

    painter->setPen(pen);
    painter->setBrush(BrushStyle::NoBrush);
    painter->drawRect(item->iconBorderRect());

    pen.setWidthF(item->lineWidth());
    pen.setStyle(PenStyle::SolidLine);

    painter->setPen(pen);
    painter->drawPath(item->iconPath());
}

void SingleDraw::draw(const LedgerLine* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    painter->setPen(Pen(item->curColor(), item->lineWidth(), PenStyle::SolidLine, PenCapStyle::FlatCap));
    if (item->vertical()) {
        painter->drawLine(LineF(0.0, 0.0, 0.0, item->len()));
    } else {
        painter->drawLine(LineF(0.0, 0.0, item->len(), 0.0));
    }
}

void SingleDraw::draw(const LetRingSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const Marker* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const MeasureNumber* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const MeasureRepeat* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    painter->setPen(item->curColor());
    item->drawSymbol(item->symId(), painter);
}

void SingleDraw::draw(const OttavaSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const PalmMuteSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const PedalSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const PickScrapeSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const PlayTechAnnotation* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const RasgueadoSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const RehearsalMark* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Rest* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (item->shouldNotBeDrawn()) {
        return;
    }
    painter->setPen(item->curColor());
    item->drawSymbol(item->sym(), painter);
}

void SingleDraw::draw(const ShadowNote* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (!item->visible() || !item->isValid()) {
        return;
    }

    PointF ap(item->pagePos());
    painter->translate(ap);
    double lw = item->style().styleMM(Sid::stemWidth) * item->mag();
    Pen pen(item->engravingConfiguration()->highlightSelectionColor(item->voice()), lw, PenStyle::SolidLine, PenCapStyle::FlatCap);
    painter->setPen(pen);

    bool up = item->computeUp();

    // Draw the accidental
    SymId acc = Accidental::subtype2symbol(item->score()->inputState().accidentalType());
    if (acc != SymId::noSym) {
        PointF posAcc;
        posAcc.rx() -= item->symWidth(acc) + item->style().styleMM(Sid::accidentalNoteDistance) * item->mag();
        item->drawSymbol(acc, painter, posAcc);
    }

    // Draw the notehead
    item->drawSymbol(item->noteheadSymbol(), painter);

    // Draw the dots
    double sp = item->spatium();
    double sp2 = sp / 2;
    double noteheadWidth = item->symWidth(item->noteheadSymbol());

    PointF posDot;
    if (item->duration().dots() > 0) {
        double d  = item->style().styleMM(Sid::dotNoteDistance) * item->mag();
        double dd = item->style().styleMM(Sid::dotDotDistance) * item->mag();
        posDot.rx() += (noteheadWidth + d);

        if (item->isRest()) {
            posDot.ry() += Rest::getDotline(item->duration().type()) * sp2;
        } else {
            posDot.ry() -= (item->lineIndex() % 2 == 0 ? sp2 : 0);
        }

        if (item->hasFlag() && up) {
            posDot.rx() = std::max(posDot.rx(), noteheadWidth + item->symBbox(item->flagSym()).right());
        }

        for (int i = 0; i < item->duration().dots(); i++) {
            posDot.rx() += dd * i;
            item->drawSymbol(SymId::augmentationDot, painter, posDot);
            posDot.rx() -= dd * i;
        }
    }

    // Draw stem and flag
    if (item->hasStem()) {
        double x = up ? (noteheadWidth - (lw / 2)) : lw / 2;
        double y1 = item->symSmuflAnchor(item->noteheadSymbol(), up ? SmuflAnchorId::stemUpSE : SmuflAnchorId::stemDownNW).y();
        double y2 = (up ? -3.5 : 3.5) * sp;

        if (item->hasFlag()) {
            SymId flag = item->flagSym();
            item->drawSymbol(flag, painter, PointF(x - (lw / 2), y2));
            y2 += item->symSmuflAnchor(flag, up ? SmuflAnchorId::stemUpNW : SmuflAnchorId::stemDownSW).y();
        }
        painter->drawLine(LineF(x, y1, x, y2));
    }

    // Draw ledger lines if needed
    if (!item->isRest() && item->lineIndex() < 100 && item->lineIndex() > -100) {
        double extraLen = item->style().styleS(Sid::ledgerLineLength).val() * sp;
        double x1 = -extraLen;
        double x2 = noteheadWidth + extraLen;
        double step = sp2 * item->staffType()->lineDistance().val();

        lw = item->style().styleMM(Sid::ledgerLineWidth) * item->mag();
        pen.setWidthF(lw);
        painter->setPen(pen);

        for (int i = -2; i >= item->lineIndex(); i -= 2) {
            double y = step * (i - item->lineIndex());
            painter->drawLine(LineF(x1, y, x2, y));
        }
        int l = item->staffType()->lines() * 2; // first ledger line below staff
        for (int i = l; i <= item->lineIndex(); i += 2) {
            double y = step * (i - item->lineIndex());
            painter->drawLine(LineF(x1, y, x2, y));
        }
    }

    item->drawArticulations(painter);

    painter->translate(-ap);
}

void SingleDraw::draw(const SlurSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    Pen pen(item->curColor());
    double mag = item->staff() ? item->staff()->staffMag(item->slur()->tick()) : 1.0;

    //Replace generic Qt dash patterns with improved equivalents to show true dots (keep in sync with tie.cpp)
    std::vector<double> dotted     = { 0.01, 1.99 };   // tighter than Qt PenStyle::DotLine equivalent - would be { 0.01, 2.99 }
    std::vector<double> dashed     = { 3.00, 3.00 };   // Compensating for caps. Qt default PenStyle::DashLine is { 4.0, 2.0 }
    std::vector<double> wideDashed = { 5.00, 6.00 };

    switch (item->slurTie()->styleType()) {
    case SlurStyleType::Solid:
        painter->setBrush(Brush(pen.color()));
        pen.setCapStyle(PenCapStyle::RoundCap);
        pen.setJoinStyle(PenJoinStyle::RoundJoin);
        pen.setWidthF(item->style().styleMM(Sid::SlurEndWidth) * mag);
        break;
    case SlurStyleType::Dotted:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setCapStyle(PenCapStyle::RoundCap);           // round dots
        pen.setDashPattern(dotted);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::Dashed:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setDashPattern(dashed);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::WideDashed:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setDashPattern(wideDashed);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::Undefined:
        break;
    }
    painter->setPen(pen);
    painter->drawPath(item->path());
}

void SingleDraw::draw(const Spacer* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    auto conf = item->engravingConfiguration();

    Pen pen(conf->fontPrimaryColor(), item->spatium() * 0.3);

    painter->setPen(pen);
    painter->setBrush(BrushStyle::NoBrush);
    painter->drawPath(item->path());
}

void SingleDraw::draw(const StaffState* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    auto conf = item->engravingConfiguration();

    Pen pen(item->selected() ? conf->selectionColor() : conf->formattingMarksColor(),
            item->lw(), PenStyle::SolidLine, PenCapStyle::RoundCap, PenJoinStyle::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(BrushStyle::NoBrush);
    painter->drawPath(item->path());
}

void SingleDraw::draw(const StaffText* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const StaffTypeChange* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    auto conf = item->engravingConfiguration();

    double _spatium = item->style().spatium();
    double h  = _spatium * 2.5;
    double w  = _spatium * 2.5;
    double lineDist = 0.35;           // line distance for the icon 'staff lines'
    // draw icon rectangle
    painter->setPen(Pen(item->selected() ? conf->selectionColor() : conf->formattingMarksColor(),
                        item->lw(), PenStyle::SolidLine, PenCapStyle::SquareCap, PenJoinStyle::MiterJoin));
    painter->setBrush(BrushStyle::NoBrush);
    painter->drawRect(0, 0, w, h);

    // draw icon contents
    int lines = 5;
    if (item->staffType()) {
        if (item->staffType()->stemless()) {       // a single notehead represents a stemless staff
            item->drawSymbol(SymId::noteheadBlack, painter, PointF(w * 0.5 - 0.33 * _spatium, h * 0.5), 0.5);
        }
        if (item->staffType()->invisible()) {      // no lines needed. It's done.
            return;
        }
        // show up to 6 lines
        lines = std::min(item->staffType()->lines(), 6);
    }
    // calculate starting point Y for the lines from half the icon height (2.5) so staff lines appear vertically centered
    double startY = 1.25 - (lines - 1) * lineDist * 0.5;
    painter->setPen(Pen(item->selected() ? conf->selectionColor() : conf->formattingMarksColor(),
                        2.5, PenStyle::SolidLine, PenCapStyle::SquareCap, PenJoinStyle::MiterJoin));
    for (int i=0; i < lines; i++) {
        int y = (startY + i * lineDist) * _spatium;
        painter->drawLine(0, y, w, y);
    }
}

void SingleDraw::draw(const Symbol* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    if (!item->isNoteDot() || !item->staff()->isTabStaff(item->tick())) {
        painter->setPen(item->curColor());
        if (item->scoreFont()) {
            item->scoreFont()->draw(item->sym(), painter, item->magS(), PointF());
        } else {
            item->drawSymbol(item->sym(), painter);
        }
    }
}

void SingleDraw::draw(const FSymbol* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    mu::draw::Font f(item->font());
    f.setPointSizeF(f.pointSizeF() * MScore::pixelRatio);
    painter->setFont(f);
    painter->setPen(item->curColor());
    painter->drawText(PointF(0, 0), item->toString());
}

void SingleDraw::draw(const SystemDivider* item, Painter* painter)
{
    draw(static_cast<const Symbol*>(item), painter);
}

void SingleDraw::draw(const SystemText* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const TempoText* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Text* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const TextLineSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const TieSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    // hide tie toward the second chord of a cross-measure value
    if (item->tie()->endNote() && item->tie()->endNote()->chord()->crossMeasure() == CrossMeasure::SECOND) {
        return;
    }

    Pen pen(item->curColor());
    double mag = item->staff() ? item->staff()->staffMag(item->tie()->tick()) : 1.0;

    //Replace generic Qt dash patterns with improved equivalents to show true dots (keep in sync with slur.cpp)
    std::vector<double> dotted     = { 0.01, 1.99 };   // tighter than Qt PenStyle::DotLine equivalent - would be { 0.01, 2.99 }
    std::vector<double> dashed     = { 3.00, 3.00 };   // Compensating for caps. Qt default PenStyle::DashLine is { 4.0, 2.0 }
    std::vector<double> wideDashed = { 5.00, 6.00 };

    switch (item->slurTie()->styleType()) {
    case SlurStyleType::Solid:
        painter->setBrush(Brush(pen.color()));
        pen.setCapStyle(PenCapStyle::RoundCap);
        pen.setJoinStyle(PenJoinStyle::RoundJoin);
        pen.setWidthF(item->style().styleMM(Sid::SlurEndWidth) * mag);
        break;
    case SlurStyleType::Dotted:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setCapStyle(PenCapStyle::RoundCap);           // True dots
        pen.setDashPattern(dotted);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::Dashed:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setDashPattern(dashed);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::WideDashed:
        painter->setBrush(BrushStyle::NoBrush);
        pen.setDashPattern(wideDashed);
        pen.setWidthF(item->style().styleMM(Sid::SlurDottedWidth) * mag);
        break;
    case SlurStyleType::Undefined:
        break;
    }
    painter->setPen(pen);
    painter->drawPath(item->path());
}

void SingleDraw::draw(const TimeSig* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (item->staff() && !const_cast<const Staff*>(item->staff())->staffType(item->tick())->genTimesig()) {
        return;
    }
    painter->setPen(item->curColor());

    const TimeSig::DrawArgs& drawArgs = item->drawArgs();

    item->drawSymbols(drawArgs.ns, painter, drawArgs.pz, item->scale());
    item->drawSymbols(drawArgs.ds, painter, drawArgs.pn, item->scale());

    if (item->largeParentheses()) {
        item->drawSymbol(SymId::timeSigParensLeft,  painter, drawArgs.pointLargeLeftParen,  item->scale().width());
        item->drawSymbol(SymId::timeSigParensRight, painter, drawArgs.pointLargeRightParen, item->scale().width());
    }
}

void SingleDraw::draw(const Tremolo* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    if (item->isBuzzRoll()) {
        painter->setPen(item->curColor());
        item->drawSymbol(SymId::buzzRoll, painter);
    } else if (!item->twoNotes() || !item->explicitParent()) {
        painter->setBrush(Brush(item->curColor()));
        painter->setNoPen();
        painter->drawPath(item->path());
    } else if (item->twoNotes() && !item->beamSegments().empty()) {
        // two-note trems act like beams

        // make beam thickness independent of slant
        // (expression can be simplified?)
        const LineF bs = item->beamSegments().front()->line;
        double d = (std::abs(bs.y2() - bs.y1())) / (bs.x2() - bs.x1());
        if (item->beamSegments().size() > 1 && d > M_PI / 6.0) {
            d = M_PI / 6.0;
        }
        double ww = (item->style().styleMM(Sid::beamWidth).val() / 2.0) / sin(M_PI_2 - atan(d));
        painter->setBrush(Brush(item->curColor()));
        painter->setNoPen();
        for (const BeamSegment* bs1 : item->beamSegments()) {
            painter->drawPolygon(
                PolygonF({
                PointF(bs1->line.x1(), bs1->line.y1() - ww),
                PointF(bs1->line.x2(), bs1->line.y2() - ww),
                PointF(bs1->line.x2(), bs1->line.y2() + ww),
                PointF(bs1->line.x1(), bs1->line.y1() + ww),
            }),
                draw::FillRule::OddEvenFill);
        }
    }
    // for palette
    if (!item->explicitParent() && !item->twoNotes()) {
        double x = 0.0;     // bbox().width() * .25;
        Pen pen(item->curColor(), item->point(item->style().styleS(Sid::stemWidth)));
        painter->setPen(pen);
        const double sp = item->spatium();
        if (item->isBuzzRoll()) {
            painter->drawLine(LineF(x, -sp, x, item->bbox().bottom() + sp));
        } else {
            painter->drawLine(LineF(x, -sp * .5, x, item->path().boundingRect().height() + sp));
        }
    }
}

void SingleDraw::draw(const TremoloBar* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    Pen pen(item->curColor(), item->lineWidth().val(), PenStyle::SolidLine, PenCapStyle::RoundCap, PenJoinStyle::RoundJoin);
    painter->setPen(pen);
    painter->drawPolyline(item->polygon());
}

void SingleDraw::draw(const TrillSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setPen(item->spanner()->curColor());
    item->drawSymbols(item->symbols(), painter);
}

void SingleDraw::draw(const TripletFeel* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextBase(item, painter);
}

void SingleDraw::draw(const Tuplet* item, Painter* painter)
{
    TRACE_DRAW_ITEM;

    // if in a TAB without stems, tuplets are not shown
    const StaffType* stt = item->staffType();
    if (stt && stt->isTabStaff() && stt->stemless()) {
        return;
    }

    Color color(item->curColor());
    if (item->number()) {
        painter->setPen(color);
        PointF pos(item->number()->pos());
        painter->translate(pos);
        draw(item->number(), painter);
        painter->translate(-pos);
    }
    if (item->hasBracket()) {
        painter->setPen(Pen(color, item->bracketWidth().val() * item->mag()));
        if (!item->number()) {
            painter->drawPolyline(item->bracketL, 4);
        } else {
            painter->drawPolyline(item->bracketL, 3);
            painter->drawPolyline(item->bracketR, 3);
        }
    }
}

void SingleDraw::draw(const VibratoSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    painter->setPen(item->spanner()->curColor());
    item->drawSymbols(item->symbols(), painter);
}

void SingleDraw::draw(const VoltaSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}

void SingleDraw::draw(const WhammyBarSegment* item, Painter* painter)
{
    TRACE_DRAW_ITEM;
    drawTextLineBaseSegment(item, painter);
}
