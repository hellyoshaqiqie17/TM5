import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

# Set style
plt.rcParams['font.sans-serif'] = 'DejaVu Sans'
plt.rcParams['font.family'] = 'sans-serif'

# ==============================================================================
# 1. DIAGRAM LINEAR QUEUE
# ==============================================================================
fig, ax = plt.subplots(figsize=(10, 4.5), dpi=300)
ax.set_xlim(-1, 9)
ax.set_ylim(-1, 4)
ax.axis('off')

# Title
ax.text(4, 3.5, "Struktur Data Linear Array Queue", fontsize=14, fontweight='bold', ha='center', color='#1a365d')
ax.text(4, 3.0, "Prinsip First-In First-Out (FIFO) dengan Pergeseran Elemen saat Dequeue", fontsize=10, fontstyle='italic', ha='center', color='#4a5568')

# Draw array boxes
slots = 8
data_vals = ["15", "28", "42", "99", "10", "-", "-", "-"]
for i in range(slots):
    # box
    bg = '#ebf8ff' if i < 5 else '#edf2f7'
    ec = '#3182ce' if i < 5 else '#a0aec0'
    rect = patches.FancyBboxPatch((i, 1.2), 0.85, 0.9, boxstyle="round,pad=0.05", ec=ec, fc=bg, lw=2)
    ax.add_patch(rect)
    
    # Text inside
    ax.text(i + 0.425, 1.65, data_vals[i], fontsize=13, fontweight='bold', ha='center', va='center', color='#2b6cb0' if i < 5 else '#a0aec0')
    
    # Index below
    ax.text(i + 0.425, 0.85, f"[{i}]", fontsize=10, ha='center', va='center', color='#718096')

# Annotate Head & Tail
# Head at 0
ax.annotate('Head (Front) = 0\n[Elemen Pertama]', xy=(0.425, 2.2), xytext=(0.425, 3.0),
            ha='center', fontsize=9, fontweight='bold', color='#c53030',
            arrowprops=dict(facecolor='#c53030', edgecolor='#c53030', width=1.5, headwidth=7, shrink=0.08))

# Tail at 4
ax.annotate('Tail (Rear) = 4\n[Elemen Terakhir]', xy=(4.425, 2.2), xytext=(4.425, 3.0),
            ha='center', fontsize=9, fontweight='bold', color='#2b6cb0',
            arrowprops=dict(facecolor='#2b6cb0', edgecolor='#2b6cb0', width=1.5, headwidth=7, shrink=0.08))

# Dequeue arrow (Keluar di Head)
ax.annotate('', xy=(-0.7, 1.65), xytext=(-0.05, 1.65),
            arrowprops=dict(facecolor='#e53e3e', edgecolor='#e53e3e', width=2, headwidth=8))
ax.text(-0.8, 1.65, 'DEQUEUE\n(Keluar)', fontsize=10, fontweight='bold', color='#e53e3e', ha='right', va='center')

# Enqueue arrow (Masuk di Tail)
ax.annotate('', xy=(5.0, 1.65), xytext=(6.5, 1.65),
            arrowprops=dict(facecolor='#38a169', edgecolor='#38a169', width=2, headwidth=8))
ax.text(6.6, 1.65, 'ENQUEUE\n(Masuk)', fontsize=10, fontweight='bold', color='#38a169', ha='left', va='center')

# Shift arrow annotation below
ax.annotate('', xy=(0.425, 0.45), xytext=(4.425, 0.45),
            arrowprops=dict(arrowstyle="<->", color="#805ad5", lw=1.5))
ax.text(2.425, 0.15, "Pergeseran Elemen ke Depan: O(N) Waktu Komputasi", fontsize=9, ha='center', color="#6b46c1", fontweight='bold')

plt.tight_layout()
fig.savefig(r"d:\tugas\TM5\images\queue_linear.png", dpi=300)
plt.close(fig)
print("Saved queue_linear.png")

# ==============================================================================
# 2. DIAGRAM CIRCULAR QUEUE
# ==============================================================================
fig, ax = plt.subplots(figsize=(8, 7.5), dpi=300)
ax.set_xlim(-4.5, 4.5)
ax.set_ylim(-4.5, 4.5)
ax.axis('off')

# Title
ax.text(0, 4.0, "Struktur Data Circular Queue (Array Melingkar)", fontsize=13, fontweight='bold', ha='center', color='#1a365d')
ax.text(0, 3.6, "Pemanfaatan Aritmatika Modulo (tail + 1) % MAX Tanpa Pergeseran Elemen", fontsize=9, fontstyle='italic', ha='center', color='#4a5568')

n_slots = 8
angles = np.linspace(np.pi/2, np.pi/2 - 2*np.pi, n_slots, endpoint=False)
radius = 2.5
box_w = 0.9

circular_data = ["-", "10", "20", "30", "40", "50", "60", "70"]
# Let front = 0 (points to empty before start), rear = 7 (holds 70)
# Active indices: 1 to 7

for i in range(n_slots):
    ang = angles[i]
    x = radius * np.cos(ang)
    y = radius * np.sin(ang)
    
    is_active = (i != 0)
    fc = '#c6f6d5' if is_active else '#fed7d7'
    ec = '#276749' if is_active else '#9b2c2c'
    
    circle = plt.Circle((x, y), 0.55, facecolor=fc, edgecolor=ec, lw=2.2, zorder=2)
    ax.add_patch(circle)
    
    # Label value
    ax.text(x, y + 0.05, circular_data[i], fontsize=11, fontweight='bold', ha='center', va='center', color='#1a202c', zorder=3)
    # Label slot index
    ax.text(x, y - 0.28, f"slot {i}", fontsize=7.5, ha='center', va='center', color='#4a5568', zorder=3)

# Draw connecting circle line
circ_outline = plt.Circle((0, 0), radius, fill=False, edgecolor='#cbd5e0', linestyle='--', lw=2, zorder=1)
ax.add_patch(circ_outline)

# Circular arrow in center showing clock-wise rotation
arc = patches.Arc((0, 0), 2.2, 2.2, angle=0, theta1=20, theta2=310, edgecolor='#4299e1', lw=2.5, linestyle='-')
ax.add_patch(arc)
ax.annotate('', xy=(1.1 * np.cos(np.radians(20)), 1.1 * np.sin(np.radians(20))),
            xytext=(1.1 * np.cos(np.radians(25)), 1.1 * np.sin(np.radians(25))),
            arrowprops=dict(facecolor='#4299e1', edgecolor='#4299e1', headwidth=8, width=2))
ax.text(0, 0.15, "Arah Rotasi\nModulo (%)", fontsize=10, fontweight='bold', ha='center', va='center', color='#2b6cb0')
ax.text(0, -0.4, "O(1) Enqueue & Dequeue", fontsize=8.5, ha='center', va='center', color='#718096')

# Annotate Front & Rear
# Front at slot 0 (angle = pi/2)
ax.annotate('Front = 0\n(Titik Kosong)', xy=(0, 2.5 + 0.6), xytext=(0, 3.4),
            ha='center', fontsize=9, fontweight='bold', color='#c53030',
            arrowprops=dict(facecolor='#c53030', edgecolor='#c53030', width=1.5, headwidth=6, shrink=0.1))

# Rear at slot 7 (angle = pi/2 + 2pi/8 = 112.5 deg)
ang7 = angles[7]
x7 = radius * np.cos(ang7)
y7 = radius * np.sin(ang7)
ax.annotate('Rear = 7\n(Elemen Terakhir: 70)', xy=(x7 - 0.5, y7 + 0.3), xytext=(x7 - 1.8, y7 + 0.8),
            ha='center', fontsize=9, fontweight='bold', color='#276749',
            arrowprops=dict(facecolor='#276749', edgecolor='#276749', width=1.5, headwidth=6, shrink=0.1))

plt.tight_layout()
fig.savefig(r"d:\tugas\TM5\images\queue_circular.png", dpi=300)
plt.close(fig)
print("Saved queue_circular.png")

# ==============================================================================
# 3. DIAGRAM LINKED LIST QUEUE
# ==============================================================================
fig, ax = plt.subplots(figsize=(10.5, 4.2), dpi=300)
ax.set_xlim(-1, 10)
ax.set_ylim(-1, 3.5)
ax.axis('off')

# Title
ax.text(4.5, 3.2, "Struktur Data Linked List Queue (Senarai Berantai)", fontsize=13, fontweight='bold', ha='center', color='#1a365d')
ax.text(4.5, 2.8, "Alokasi Memori Dinamis (Heap) dengan Pointer Front dan Rear", fontsize=9, fontstyle='italic', ha='center', color='#4a5568')

node_vals = [100, 200, 300, 400]
x_positions = [0.5, 2.8, 5.1, 7.4]

for i, (val, xpos) in enumerate(zip(node_vals, x_positions)):
    # Data part
    rect_data = patches.FancyBboxPatch((xpos, 1.0), 1.0, 0.9, boxstyle="round,pad=0.03", ec='#319795', fc='#e6fffa', lw=1.8)
    ax.add_patch(rect_data)
    ax.text(xpos + 0.5, 1.45, str(val), fontsize=11, fontweight='bold', ha='center', va='center', color='#234e52')
    ax.text(xpos + 0.5, 0.75, "data", fontsize=8, ha='center', color='#4a5568')

    # Next pointer part
    rect_next = patches.FancyBboxPatch((xpos + 1.05, 1.0), 0.55, 0.9, boxstyle="round,pad=0.03", ec='#319795', fc='#b2f5ea', lw=1.8)
    ax.add_patch(rect_next)
    ax.text(xpos + 1.325, 1.45, "•", fontsize=14, fontweight='bold', ha='center', va='center', color='#234e52')
    ax.text(xpos + 1.325, 0.75, "next", fontsize=8, ha='center', color='#4a5568')
    
    # Arrow to next node
    if i < len(node_vals) - 1:
        next_x = x_positions[i+1]
        ax.annotate('', xy=(next_x - 0.05, 1.45), xytext=(xpos + 1.35, 1.45),
                    arrowprops=dict(facecolor='#319795', edgecolor='#319795', width=1.5, headwidth=6, shrink=0.05))
    else:
        # Arrow to NULL
        ax.annotate('', xy=(xpos + 2.2, 1.45), xytext=(xpos + 1.35, 1.45),
                    arrowprops=dict(facecolor='#e53e3e', edgecolor='#e53e3e', width=1.5, headwidth=6, shrink=0.05))
        ax.text(xpos + 2.25, 1.45, "NULL", fontsize=10, fontweight='bold', color='#e53e3e', va='center')

# Front Pointer
ax.annotate('Front\n(0x7fff01)', xy=(1.0, 1.95), xytext=(1.0, 2.65),
            ha='center', fontsize=9, fontweight='bold', color='#c53030',
            arrowprops=dict(facecolor='#c53030', edgecolor='#c53030', width=1.5, headwidth=6, shrink=0.08))

# Rear Pointer
ax.annotate('Rear\n(0x7fff04)', xy=(7.9, 1.95), xytext=(7.9, 2.65),
            ha='center', fontsize=9, fontweight='bold', color='#2b6cb0',
            arrowprops=dict(facecolor='#2b6cb0', edgecolor='#2b6cb0', width=1.5, headwidth=6, shrink=0.08))

# Dequeue action at front
ax.annotate('', xy=(-0.6, 1.45), xytext=(0.4, 1.45),
            arrowprops=dict(facecolor='#e53e3e', edgecolor='#e53e3e', width=2, headwidth=7))
ax.text(-0.7, 1.45, 'DEQUEUE\n(Free Front)', fontsize=9, fontweight='bold', color='#e53e3e', ha='right', va='center')

# Enqueue action at rear
ax.annotate('', xy=(8.7, 0.4), xytext=(7.9, 0.4),
            arrowprops=dict(facecolor='#38a169', edgecolor='#38a169', width=2, headwidth=7))
ax.text(8.8, 0.4, 'ENQUEUE (malloc & hubungkan Rear->next)', fontsize=9, fontweight='bold', color='#38a169', va='center')

plt.tight_layout()
fig.savefig(r"d:\tugas\TM5\images\queue_linked_list.png", dpi=300)
plt.close(fig)
print("Saved queue_linked_list.png")

# ==============================================================================
# 4. DIAGRAM KOMPARASI KINERJA STRUKTUR DATA QUEUE
# ==============================================================================
fig, ax = plt.subplots(figsize=(9, 4), dpi=300)
ax.axis('off')

# Table data
col_labels = ["Struktur Data", "Kompleksitas Enqueue", "Kompleksitas Dequeue", "Kapasitas Memori", "Overhead Memori"]
table_data = [
    ["Linear Array Queue", "O(1)", "O(N) [Shifting Loop]", "Statis / Tetap (MAX)", "Minimal (Hanya array & indeks)"],
    ["Circular Array Queue", "O(1)", "O(1) [Modulo Pointer]", "Statis / Tetap (MAX-1)", "Minimal (Tanpa shifting)"],
    ["Linked List Queue", "O(1)", "O(1) [Pointer Re-link]", "Dinamis (Heap Tak Terbatas)", "Pointer overhead (next pointer per node)"]
]

table = ax.table(cellText=table_data, colLabels=col_labels, loc='center', cellLoc='center')
table.auto_set_font_size(False)
table.set_fontsize(9)
table.scale(1.15, 1.9)

# Style header
for (row, col), cell in table.get_celld().items():
    if row == 0:
        cell.set_facecolor('#2b6cb0')
        cell.set_text_props(color='white', weight='bold')
    else:
        if row % 2 == 1:
            cell.set_facecolor('#edf2f7')
        else:
            cell.set_facecolor('#ffffff')
        cell.set_edgecolor('#cbd5e0')

ax.set_title("Tabel Komparasi Karakteristik dan Kompleksitas Implementasi Queue", fontsize=12, fontweight='bold', color='#1a365d', pad=15)
plt.tight_layout()
fig.savefig(r"d:\tugas\TM5\images\queue_comparison.png", dpi=300)
plt.close(fig)
print("Saved queue_comparison.png")
